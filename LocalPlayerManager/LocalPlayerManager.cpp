// LocalPlayerManager.cpp
// Defines LocalPlayer class

// INCLUDE SPACE =========================================
#include "stdafx.h"
// =======================================================

namespace EdgeLibrary
{
	#pragma region LOCAL PLAYER FUNCTIONS

	//Returns the Base Address of LocalPlayer as DWORD
	DWORD LocalPlayer::GetLocalPlayerBaseAddress()
	{
		return MemoryManager::Read<DWORD>((DWORD)Resources::ClientDLL.modBaseAddr + Offsets::m_dwLocalPlayer);
	}

	//Returns the ID of the crosshair as int
	int LocalPlayer::GetCrosshairID()
	{
		return MemoryManager::Read<int>(LocalPlayer::GetLocalPlayerBaseAddress() + Offsets::m_iCrossHairID) - 1;
	}

	//Returns the FeetPosition of LocalPlayer as Vector3
	Vector3 LocalPlayer::GetVecOrigin()
	{
		return MemoryManager::Read<Vector3>(LocalPlayer::GetLocalPlayerBaseAddress() + Offsets::m_vecOrigin);
	}

	//Returns the current Team of LocalPlayer as int
	int LocalPlayer::GetTeam()
	{
		return MemoryManager::Read<int>(LocalPlayer::GetLocalPlayerBaseAddress() + Offsets::m_iTeamNum);
	}

	//Returns the current Health of LocalPlayer as int
	int LocalPlayer::GetHealth()
	{
		return MemoryManager::Read<int>(LocalPlayer::GetLocalPlayerBaseAddress() + Offsets::m_iHealth);
	}

	//Returns the current FlashMaxAlpha of LocalPlayer as float
	float LocalPlayer::GetFlashMaxAlpha()
	{
		return MemoryManager::Read<float>(LocalPlayer::GetLocalPlayerBaseAddress() + Offsets::m_flFlashMaxAlpha);
	}

	//Returns the current EyePosition of LocalPlayer as Vector3
	Vector3 LocalPlayer::GetEyePos()
	{
		return MemoryManager::Read<Vector3>(LocalPlayer::GetLocalPlayerBaseAddress() + Offsets::m_angEyeAngles);
	}

	//Returns the current Armor of LocalPlayer as int
	int LocalPlayer::GetArmor()
	{
		return MemoryManager::Read<int>(LocalPlayer::GetLocalPlayerBaseAddress() + Offsets::m_ArmorValue);
	}

	//Returns the number of shots fired in a single spray until LocalPlayer lets go of +attack as int
	int LocalPlayer::GetShotsFired()
	{
		return MemoryManager::Read<int>(LocalPlayer::GetLocalPlayerBaseAddress() + Offsets::m_iShotsFired);
	}

	//Returns the Flags of LocalPlayer as BYTE
	BYTE LocalPlayer::GetFlags()
	{
		return MemoryManager::Read<BYTE>(LocalPlayer::GetLocalPlayerBaseAddress() + Offsets::m_fFlags);
	}

	//Returns the current ViewAngles of LocalPlayer as Vector3
	Vector3 LocalPlayer::GetViewAngles()
	{
		return MemoryManager::Read<Vector3>(LocalPlayer::GetLocalPlayerBaseAddress() + Offsets::m_dwViewAngles);
	}

	//Returns the current Velocity of LocalPlayer as Vector3
	Vector3 LocalPlayer::GetVecVelocity()
	{
		return MemoryManager::Read<Vector3>(LocalPlayer::GetLocalPlayerBaseAddress() + Offsets::m_vecVelocity);
	}

	//Returns the current PunchAngles of LocalPlayer as Vector3
	Vector3 LocalPlayer::GetVecPunch()
	{
		return MemoryManager::Read<Vector3>(LocalPlayer::GetLocalPlayerBaseAddress() + Offsets::m_vecPunch);
	}

	//Returns ClientState (some people call it EnginePointer) as DWORD
	DWORD LocalPlayer::GetClientState()
	{
		return MemoryManager::Read<DWORD>((DWORD)Resources::EngineDLL.modBaseAddr + Offsets::m_dwClientState);
	}

	//Returns the current sensitivity of LocalPlayer as float
	float LocalPlayer::GetSens()
	{
		return MemoryManager::Read<float>((DWORD)Resources::ClientDLL.modBaseAddr + Offsets::m_dwSensitivity);
	}

	//Sets FlashMaxAlpha of LocalPlayer to a given value, returns true if it succeeds, returns false if it fails
	bool LocalPlayer::SetFlashMaxAlpha(float Value)
	{
		if (MemoryManager::Write<float>(LocalPlayer::GetLocalPlayerBaseAddress() + Offsets::m_flFlashMaxAlpha, Value))
			return true;
		else
			return false;
	}

	//Sets the ViewAngles of LocalPlayer to a given Vector3, returns true if it succeeds, returns false if it fails
	bool LocalPlayer::SetViewAngles(Vector3 AnglesToSet)
	{
		if (MemoryManager::Write<Vector3>(LocalPlayer::GetClientState() + Offsets::m_dwViewAngles, AnglesToSet))
			return true;
		else
			return false;
	}

	//Sets the Sensitivity of LocalPlayer to a given float, returns true if it suceeds, returns false if it fails
	bool LocalPlayer::SetSens(float Sens)
	{
		if (MemoryManager::Write<float>((DWORD)Resources::ClientDLL.modBaseAddr + Offsets::m_dwSensitivity, Sens))
			return true;
		else
			return false;
	}

	#pragma endregion
}