// EntityManager.cpp
// Defines Entity class

// INCLUDE SPACE =========================================
#include "stdafx.h"
// =======================================================

namespace EdgeLibrary
{
#pragma region ENTITY FUNCTIONS
	//Returns the BaseAddress of an Entity by passing the specific ID of that Entity. Returns DWORD
	DWORD Entity::GetEntityBaseAddress(int Index)
	{
		return MemoryManager::Read<DWORD>((DWORD)Resources::ClientDLL.modBaseAddr + Offsets::m_dwEntityList + (Index * 0x10));
	}

	Vector3 Entity::GetEyePos(int Index)
	{
		return MemoryManager::Read<Vector3>(Entity::GetEntityBaseAddress(Index) + Offsets::m_angEyeAngles);
	}

	//Returns the TeamID of a given Entity by Index as int
	int Entity::GetTeam(int Index)
	{
		return MemoryManager::Read<int>(Entity::GetEntityBaseAddress(Index) + Offsets::m_iTeamNum);
	}

	//Returns the current Health of a given Entity by Index as int
	int Entity::GetHealth(int Index)
	{
		return MemoryManager::Read<int>(Entity::GetEntityBaseAddress(Index) + Offsets::m_iHealth);
	}

	//Returns the current dormant state of a given Entity by Index as bool
	bool Entity::GetDormant(int Index)
	{
		return MemoryManager::Read<bool>(Entity::GetEntityBaseAddress(Index) + Offsets::m_bDormant);
	}

	//Returns the current bSpotted state of a given Entity by Index as bool
	bool Entity::GetbSpotted(int Index)
	{
		return MemoryManager::Read<bool>(Entity::GetEntityBaseAddress(Index) + Offsets::m_bSpotted);
	}

	//Returns the distance to a given Entity by Index as float
	float Entity::GetDistanceFromEntity(int Index)
	{
		Vector3 dest = Entity::GetFeetPosition(Index);
		Vector3 src = LocalPlayer::GetVecOrigin();

		return sqrt(pow((src.x - dest.x), 2) + pow((src.y - dest.y), 2) + pow((src.z - dest.z), 2));
	}

	//Returns the BoneBase of a given Entity by Index as DWORD
	DWORD Entity::GetBoneBase(int Index)
	{
		return MemoryManager::Read<DWORD>(Entity::GetEntityBaseAddress(Index) + Offsets::m_dwBoneMatrix);
	}

	//Returns the FeetPosition of a given Entity by Index as Vector3
	Vector3 Entity::GetFeetPosition(int Index)
	{
		return MemoryManager::Read<Vector3>(Entity::GetEntityBaseAddress(Index) + Offsets::m_vecOrigin);
	}

	//Returns the GlowIndex of a given Entity by Index as int
	int Entity::GetGlowIndex(int Index)
	{
		return MemoryManager::Read<int>(Entity::GetEntityBaseAddress(Index) + Offsets::m_iGlowIndex);
	}

	//Returns if a given Entity is alive as bool
	bool Entity::GetAliveState(int Index)
	{
		return !Entity::GetDormant(Index) && Entity::GetHealth(Index) < 100 && Entity::GetHealth(Index) > 100;
	}

	//Sets bSpotted of a given Entity by Index to a given value, returns true if it succeeds, returns false if it fails
	bool Entity::SetbSpotted(int Index, int Value)
	{
		if (MemoryManager::Write<bool>(Entity::GetEntityBaseAddress(Index) + Offsets::m_bSpotted, Value))
			return true;
		else
			return false;
	}
#pragma endregion
}