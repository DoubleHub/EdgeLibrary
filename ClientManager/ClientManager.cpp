// ClientManager.cpp
// Defines Client class

// INCLUDE SPACE =========================================
#include "stdafx.h"
// =======================================================

namespace EdgeLibrary
{
#pragma region CLIENT FUNCTIONS

	//Returns the current state of +attack as int
	int Client::GetAttack()
	{
		return MemoryManager::Read<int>((DWORD)Resources::ClientDLL.modBaseAddr + Offsets::m_dwForceAttack);
	}

	//Returns the current state of +forward as int
	int Client::GetMoveForward()
	{
		//Mi manca l'offset m_dwForceMoveForward
		return 0;
	}

	//Returns the current state of +jump as int
	int Client::GetJump()
	{
		return MemoryManager::Read<int>((DWORD)Resources::ClientDLL.modBaseAddr + Offsets::m_dwForceJump);
	}

	//Returns the GlowPointer as DWORD
	DWORD Client::GetGlowPointer()
	{
		return MemoryManager::Read<DWORD>((DWORD)Resources::ClientDLL.modBaseAddr + Offsets::m_dwGlowObject);
	}

	//Sets +attack to a given value, returns true if it succeeds, returns false if it fails
	bool Client::SetAttack(int Value)
	{
		if (MemoryManager::Write<int>((DWORD)Resources::ClientDLL.modBaseAddr + Offsets::m_dwForceAttack, Value))
			return true;
		else
			return false;
	}

	//Sets +forward to a given value, returns true if it succeeds, returns false if it fails
	bool Client::SetMoveForward(int Value)
	{
		//Mi manca l'offset m_dwForceMoveForward
		return false;
	}

	//Sets +jump to a given value, returns true if it succeeds, returns false if it fails
	bool Client::SetJump(int Value)
	{
		if (MemoryManager::Write<int>((DWORD)Resources::ClientDLL.modBaseAddr + Offsets::m_dwForceJump, Value))
			return true;
		else
			return false;
	}

#pragma endregion
}