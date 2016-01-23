// CHEntityManager.cpp
// Defines CHEntity class
 
//INCLUDE SPACE =======
#include "stdafx.h"
//=====================
 
namespace EdgeLibrary
{
 
    #pragma region CHENTITY FUNCTIONS
 
    DWORD CHEntity::GetEntityBase()
    {
		return MemoryManager::Read<DWORD>((DWORD)Resources::ClientDLL.modBaseAddr + Offsets::m_dwEntityList + (LocalPlayer::GetCrosshairID() * 0x10));
    }
 
    int CHEntity::GetHealth()
    {
        return MemoryManager::Read<int>(CHEntity::GetEntityBase() + Offsets::m_iHealth);
    }
 
    int CHEntity::GetTeam()
    {
        return MemoryManager::Read<int>(CHEntity::GetEntityBase() + Offsets::m_iTeamNum);
    }
 
    Vector3 CHEntity::GetVecOrigin()
    {
        return MemoryManager::Read<Vector3>(CHEntity::GetEntityBase() + Offsets::m_vecOrigin);
    }
 
    Vector3 CHEntity::GetEyePos()
    {
        return MemoryManager::Read<Vector3>(CHEntity::GetEntityBase() + Offsets::m_angEyeAngles);
    }
 
    DWORD CHEntity::GetBoneBase()
    {
		return MemoryManager::Read<DWORD>(CHEntity::GetEntityBase() + Offsets::m_dwBoneMatrix);
    }
 
    #pragma endregion
 
}