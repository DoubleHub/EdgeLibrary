// MemoryManager.cpp
// Defines MemoryManager class

// INCLUDE SPACE ====================================
#include "stdafx.h"
#include <TlHelp32.h>
// ==================================================

namespace EdgeLibrary
{
#pragma region PRIVATE STUFF
	HANDLE MemoryManager::hProcess = NULL;
	DWORD MemoryManager::dwPID = NULL;
	bool MemoryManager::DataCompare(const BYTE* pData, const BYTE* pMask, const char* pszMask) 
	{
	for (; *pszMask; ++pszMask, ++pData, ++pMask) 
	{
		if (*pszMask == 'x' && *pData != *pMask)
		{
			return false;
		}
	}

	return (*pszMask == NULL);
}
#pragma endregion
#pragma region CTOR
	MemoryManager::MemoryManager()
	{
	}
#pragma endregion
#pragma region DTOR
	MemoryManager::~MemoryManager()
	{
		CloseHandle(hProcess);
	}
#pragma endregion
#pragma region PROCESS/MODULE ATTACH FUNCTIONS DEFINITION
	bool MemoryManager::AttachProcess(char* processName)
	{
		HANDLE hPID = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
		PROCESSENTRY32 procEntry;
		procEntry.dwSize = sizeof(procEntry);

		const WCHAR* procNameChar;
		int nChars = MultiByteToWideChar(CP_ACP, 0, processName, -1, NULL, 0);
		procNameChar = new WCHAR[nChars];
		MultiByteToWideChar(CP_ACP, 0, processName, -1, (LPWSTR)procNameChar, nChars);

		do
			if (!wcscmp(procEntry.szExeFile, procNameChar))
			{
				dwPID = procEntry.th32ProcessID;
				CloseHandle(hPID);
				hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID);
				return true;
			}
		while (Process32Next(hPID, &procEntry));

		return false;
	}
	MODULEENTRY32 MemoryManager::AttachModule(char* moduleName)
	{
		HANDLE hModule = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwPID);
		MODULEENTRY32 mEntry;
		mEntry.dwSize = sizeof(mEntry);

		const WCHAR *modNameChar;
		int nChars = MultiByteToWideChar(CP_ACP, 0, moduleName, -1, NULL, 0);
		modNameChar = new WCHAR[nChars];
		MultiByteToWideChar(CP_ACP, 0, moduleName, -1, (LPWSTR)modNameChar, nChars);

		do
			if (!wcscmp(mEntry.szModule, modNameChar))
			{
				CloseHandle(hModule);
				return mEntry;
			}
		while (Module32Next(hModule, &mEntry));

		mEntry.modBaseAddr = 0x0;
		return mEntry;
	}
#pragma endregion
#pragma region PATTERN SCANNING FOR OFFSETS
//Find pattern for offsets based on signature and mask
DWORD MemoryManager::FindPattern(DWORD start, DWORD size, const char* sig, const char* mask) 
{
	BYTE* data = new BYTE[size];

	unsigned long bytesRead;

	if (!ReadProcessMemory(hProcess, (LPVOID)start, data, size, &bytesRead))
	{
		delete[] sig;
		delete[] data;
		return NULL;
	}

	for (DWORD i = 0; i < size; i++) 
	{
		if (DataCompare((const BYTE*)(data + i), (const BYTE*)sig, mask))
		{
			delete[] sig;
			delete[] data;
			return start + i;
		}
	}
	delete[] sig;
	delete[] data;
	return NULL;
}
//Find the array of pattern
DWORD MemoryManager::FindPatternArr(DWORD start, DWORD size, const char* mask, int count, ...) 
{
	char* sig = new char[count + 1];
	va_list ap;
	va_start(ap, count);
	for (int i = 0; i < count; i++) 
	{
		char read = va_arg(ap, char);
		sig[i] = read;
	}
	va_end(ap);
	sig[count] = '\0';
	return FindPattern(start, size, sig, mask);
}
#pragma endregion
#pragma region GETTERS
	HANDLE MemoryManager::GetProcessHandle()
	{
		return MemoryManager::hProcess;
	}
	DWORD MemoryManager::GetProcessID()
	{
		return MemoryManager::dwPID;	
	}
#pragma endregion
}