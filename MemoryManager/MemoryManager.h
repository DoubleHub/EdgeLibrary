// MemoryManager.h
// Declares MemoryManager class

#pragma once
// INCLUDE SPACE =========================================
#include "stdafx.h"
// =======================================================

namespace EdgeLibrary
{

//MemoryManager class is used to perform various tasks that handle memory
class MemoryManager
{
private:
	#pragma region PRIVATE STUFF
	//The process' handle
	static HANDLE hProcess;
	//The process' ID
	static DWORD dwPID;
	//Compares data in a mask
	static bool DataCompare(const BYTE* pData, const BYTE* pMask, const char* pszMask);
	#pragma endregion
public:
	#pragma region CTOR AND DTOR
	//This is the ctor of Memory class
	MemoryManager();
	//This is the dtor of Memory class
	~MemoryManager();
	#pragma endregion
	#pragma region GETTERS
	//Returns hProcess
	HANDLE GetProcessHandle();
	//Returns dwPID
	DWORD GetProcessID();
	#pragma endregion
	#pragma region MEMORY FUNCTIONS
	template<class c>
	//Read an address and return the value found
	static c Read(DWORD dwAddress)
	{
		c read;
		ReadProcessMemory(hProcess, (LPVOID)dwAddress, &read, sizeof(c), NULL);
		return read;
	}

	template<class c>
	//Read an address and directly assign the value to a variable
	static c Read(DWORD dwAddress, c value)
	{
		ReadProcessMemory(hProcess, (LPVOID)dwAddress, &value, sizeof(c), NULL);
	}

	template<class c>
	//Writes into an address a value
	static bool Write(DWORD dwAddress, c value)
	{
		if (WriteProcessMemory(hProcess, (LPVOID)dwAddress, &value, sizeof(c), NULL))
			return true;
		else return false;
	}
	#pragma endregion
	#pragma region PROCESS/MODULE ATTACH FUNCTIONS
	//Attach to a process, returns true if all went good
	static bool AttachProcess(char* processName);
	//Attach to a module, returns his BaseAddress, otherwise returns 0 if something went wrong
	static MODULEENTRY32 AttachModule(LPSTR moduleName);
    #pragma endregion
	#pragma region PATTERN SCANNING FOR OFFSETS
	static DWORD FindPattern(DWORD start, DWORD size, const char* sig, const char* mask);
	static DWORD FindPatternArr(DWORD start, DWORD size, const char* mask, int count, ...);
	#pragma endregion
};

}