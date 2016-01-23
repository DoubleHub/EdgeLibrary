// OffsetManager.cpp
// Defines Offsets class

// INCLUDE SPACE =========================================
#include "stdafx.h"
// =======================================================

namespace EdgeLibrary
{
#pragma region OFFSETS
	DWORD Offsets::m_fAccuracyPenalty = NULL;
	DWORD Offsets::m_nForceBone = NULL;
	DWORD Offsets::m_iState = NULL;
	DWORD Offsets::m_iClip1 = NULL;
	DWORD Offsets::m_flNextPrimaryAttack = NULL;
	DWORD Offsets::m_bCanReload = NULL;
	DWORD Offsets::m_iPrimaryAmmoType = NULL;
	DWORD Offsets::m_iWeaponID = NULL;
	DWORD Offsets::m_zoomLevel = NULL;
	DWORD Offsets::m_bSpotted = NULL;
	DWORD Offsets::m_bSpottedByMask = NULL;
	DWORD Offsets::m_hOwnerEntity = NULL;
	DWORD Offsets::m_vecOrigin = NULL;
	DWORD Offsets::m_iTeamNum = NULL;
	DWORD Offsets::m_flFlashMaxAlpha = NULL;
	DWORD Offsets::m_flFlashDuration = NULL;
	DWORD Offsets::m_iGlowIndex = NULL;
	DWORD Offsets::m_angEyeAngles = NULL;
	DWORD Offsets::m_iAccount = NULL;
	DWORD Offsets::m_ArmorValue = NULL;
	DWORD Offsets::m_bGunGameImmunity = NULL;
	DWORD Offsets::m_iShotsFired = NULL;
	DWORD Offsets::CSPlayerResource = NULL;
	DWORD Offsets::m_iCompetitiveRanking = NULL;
	DWORD Offsets::m_iCompetitiveWins = NULL;
	DWORD Offsets::m_iKills = NULL;
	DWORD Offsets::m_iAssists = NULL;
	DWORD Offsets::m_iDeaths = NULL;
	DWORD Offsets::m_iPing = NULL;
	DWORD Offsets::m_iScore = NULL;
	DWORD Offsets::m_szClan = NULL;
	DWORD Offsets::m_lifeState = NULL;
	DWORD Offsets::m_fFlags = NULL;
	DWORD Offsets::m_iHealth = NULL;
	DWORD Offsets::m_hLastWeapon = NULL;
	DWORD Offsets::m_hMyWeapons = NULL;
	DWORD Offsets::m_hActiveWeapons = NULL;
	DWORD Offsets::m_Local = NULL;
	DWORD Offsets::m_vecViewOffset = NULL;
	DWORD Offsets::m_nTickBase = NULL;
	DWORD Offsets::m_vecVelocity = NULL;
	DWORD Offsets::m_szLastPlaceName = NULL;
	DWORD Offsets::m_vecPunch = NULL;
	DWORD Offsets::m_iCrossHairID = NULL;
	DWORD Offsets::m_dwModel = NULL;
	DWORD Offsets::m_dwIndex = NULL;
	DWORD Offsets::m_dwBoneMatrix = NULL;
	DWORD Offsets::m_bMoveType = NULL;
	DWORD Offsets::m_bDormant = NULL;
	DWORD Offsets::m_dwClientState = NULL;
	DWORD Offsets::m_dwLocalPlayerIndex = NULL;
	DWORD Offsets::m_dwInGame = NULL;
	DWORD Offsets::m_dwMaxPlayer = NULL;
	DWORD Offsets::m_dwMapDirectory = NULL;
	DWORD Offsets::m_dwMapName = NULL;
	DWORD Offsets::m_dwPlayerInfo = NULL;
	DWORD Offsets::m_dwViewAngles = NULL;
	DWORD Offsets::m_dwViewMatrix = NULL;
	DWORD Offsets::m_dwEnginePosition = NULL;
	DWORD Offsets::m_dwRadarBase = NULL;
	DWORD Offsets::m_dwRadarBasePointer = NULL;
	DWORD Offsets::m_dwLocalPlayer = NULL;
	DWORD Offsets::m_dwEntityList = NULL;
	DWORD Offsets::m_dwWeaponTable = NULL;
	DWORD Offsets::m_dwWeaponTableIndex = NULL;
	DWORD Offsets::m_dwInput = NULL;
	DWORD Offsets::m_dwGlobalVars = NULL;
	DWORD Offsets::m_dwGlowObject = NULL;
	DWORD Offsets::m_dwForceJump = NULL;
	DWORD Offsets::m_dwForceAttack = NULL;
	DWORD Offsets::m_dwSensitivity = NULL;
	DWORD Offsets::m_dwMouseEnable = NULL;
	DWORD Offsets::m_dwEntityLoopDistance = NULL;
	//Engine pointer can be taken only from Pattern Scanning from now
	DWORD Offsets::m_dwEnginePointer = NULL;
#pragma endregion
#pragma region INI FUNCTION
	void Offsets::GetOffsetsByFile(LPCSTR FilePath)
	{
		m_fAccuracyPenalty = (DWORD)GetPrivateProfileIntA("Offsets", "m_fAccuracyPenalty", NULL, FilePath);
		m_nForceBone = (DWORD)GetPrivateProfileIntA("Offsets", "m_nForceBone", NULL, FilePath);
		m_iState = (DWORD)GetPrivateProfileIntA("Offsets", "m_iState", NULL, FilePath);
		m_iClip1 = (DWORD)GetPrivateProfileIntA("Offsets", "m_iClip1", NULL, FilePath);
		m_flNextPrimaryAttack = (DWORD)GetPrivateProfileIntA("Offsets", "m_flNextPrimaryAttack", NULL, FilePath);
		m_bCanReload = (DWORD)GetPrivateProfileIntA("Offsets", "m_bCanReload", NULL, FilePath);
		m_iPrimaryAmmoType = (DWORD)GetPrivateProfileIntA("Offsets", "m_iPrimaryAmmoType", NULL, FilePath);
		m_iWeaponID = (DWORD)GetPrivateProfileIntA("Offsets", "m_iWeaponID", NULL, FilePath);
		m_bSpotted = (DWORD)GetPrivateProfileIntA("Offsets", "m_bSpotted", NULL, FilePath);
		m_bSpottedByMask = (DWORD)GetPrivateProfileIntA("Offsets", "m_bSpottedByMask", NULL, FilePath);
		m_hOwnerEntity = (DWORD)GetPrivateProfileIntA("Offsets", "m_hOwnerEntity", NULL, FilePath);
		m_vecOrigin = (DWORD)GetPrivateProfileIntA("Offsets", "m_vecOrigin", NULL, FilePath);
		m_iTeamNum = (DWORD)GetPrivateProfileIntA("Offsets", "m_iTeamNum", NULL, FilePath);
		m_flFlashMaxAlpha = (DWORD)GetPrivateProfileIntA("Offsets", "m_flFlashMaxAlpha", NULL, FilePath);
		m_flFlashDuration = (DWORD)GetPrivateProfileIntA("Offsets", "m_flFlashDuration", NULL, FilePath);
		m_iGlowIndex = (DWORD)GetPrivateProfileIntA("Offsets", "m_iGlowIndex", NULL, FilePath);
		m_angEyeAngles = (DWORD)GetPrivateProfileIntA("Offsets", "m_angEyeAngles", NULL, FilePath);
		m_iAccount = (DWORD)GetPrivateProfileIntA("Offsets", "m_iAccount", NULL, FilePath);
		m_ArmorValue = (DWORD)GetPrivateProfileIntA("Offsets", "m_ArmorValue", NULL, FilePath);
		m_bGunGameImmunity = (DWORD)GetPrivateProfileIntA("Offsets", "m_bGunGameImmunity", NULL, FilePath);
		m_iShotsFired = (DWORD)GetPrivateProfileIntA("Offsets", "m_iShotsFired", NULL, FilePath);
		m_lifeState = (DWORD)GetPrivateProfileIntA("Offsets", "m_lifeState", NULL, FilePath);
		m_fFlags = (DWORD)GetPrivateProfileIntA("Offsets", "m_fFlags", NULL, FilePath);
		m_iHealth = (DWORD)GetPrivateProfileIntA("Offsets", "m_iHealth", NULL, FilePath);
		m_hLastWeapon = (DWORD)GetPrivateProfileIntA("Offsets", "m_hLastWeapon", NULL, FilePath);
		m_hMyWeapons = (DWORD)GetPrivateProfileIntA("Offsets", "m_hMyWeapons", NULL, FilePath);
		m_hActiveWeapons = (DWORD)GetPrivateProfileIntA("Offsets", "m_hActiveWeapon", NULL, FilePath);
		m_Local = (DWORD)GetPrivateProfileIntA("Offsets", "m_Local", NULL, FilePath);
		m_vecViewOffset = (DWORD)GetPrivateProfileIntA("Offsets", "m_vecViewOffset", NULL, FilePath);
		m_nTickBase = (DWORD)GetPrivateProfileIntA("Offsets", "m_nTickBase", NULL, FilePath);
		m_vecVelocity = (DWORD)GetPrivateProfileIntA("Offsets", "m_vecVelocity", NULL, FilePath);
		m_szLastPlaceName = (DWORD)GetPrivateProfileIntA("Offsets", "m_szLastPlaceName", NULL, FilePath);
		m_vecPunch = (DWORD)GetPrivateProfileIntA("Offsets", "m_vecPunch", NULL, FilePath);
		m_iCrossHairID = (DWORD)GetPrivateProfileIntA("Offsets", "m_iCrossHairID", NULL, FilePath);
		m_dwModel = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwModel", NULL, FilePath);
		m_dwIndex = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwIndex", NULL, FilePath);
		m_dwBoneMatrix = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwBoneMatrix", NULL, FilePath);
		m_bMoveType = (DWORD)GetPrivateProfileIntA("Offsets", "m_bMoveType", NULL, FilePath);
		m_bDormant = (DWORD)GetPrivateProfileIntA("Offsets", "m_bDormant", NULL, FilePath);
		m_dwClientState = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwClientState", NULL, FilePath);
		m_dwLocalPlayerIndex = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwLocalPlayerIndex", NULL, FilePath);
		m_dwInGame = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwInGame", NULL, FilePath);
		m_dwMaxPlayer = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwMaxPlayer", NULL, FilePath);
		m_dwMapDirectory = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwMapDirectory", NULL, FilePath);
		m_dwMapName = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwMapname", NULL, FilePath);
		m_dwPlayerInfo = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwPlayerInfo", NULL, FilePath);
		m_dwViewAngles = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwViewAngles", NULL, FilePath);
		m_dwViewMatrix = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwViewMatrix", NULL, FilePath);
		m_dwEnginePosition = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwEnginePosition", NULL, FilePath);
		m_dwRadarBase = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwRadarBase", NULL, FilePath);
		m_dwRadarBasePointer = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwRadarBasePointer", NULL, FilePath);
		m_dwLocalPlayer = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwLocalPlayer", NULL, FilePath);
		m_dwEntityList = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwEntityList", NULL, FilePath);
		m_dwWeaponTable = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwWeaponTable", NULL, FilePath);
		m_dwWeaponTableIndex = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwWeaponTableIndex", NULL, FilePath);
		m_dwInput = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwInput", NULL, FilePath);
		m_dwGlobalVars = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwGlobalVars", NULL, FilePath);
		m_dwGlowObject = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwGlowObject", NULL, FilePath);
		m_dwForceJump = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwForceJump", NULL, FilePath);
		m_dwForceAttack = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwForceAttack", NULL, FilePath);
		m_dwSensitivity = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwSensitivity", NULL, FilePath);
		m_dwMouseEnable = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwMouseEnable", NULL, FilePath);
		m_dwEntityLoopDistance = (DWORD)GetPrivateProfileIntA("Offsets", "m_dwEntityLoopDistance", NULL, FilePath);
		m_dwEnginePointer = 0x0;
	}
#pragma endregion
#pragma region PATTERN SCANNING
	void Offsets::GetOffsetsByPatternScan()
	{
		#pragma region LOCAL PLAYER
		DWORD LocalPlayerArray = MemoryManager::FindPatternArr(
								(DWORD)Resources::ClientDLL.modBaseAddr, 
								Resources::ClientDLL.modBaseSize, 
								"xxx????xx????xxxxx?", 
								19, 0x8D, 0x34, 0x85, 0x0, 0x0, 0x0, 0x0, 0x89, 0x15,
								0x0, 0x0, 0x0, 0x0, 0x8B, 0x41, 0x8, 0x8B, 0x48, 0x0);
		m_dwLocalPlayer = (MemoryManager::Read<DWORD>(LocalPlayerArray + 3)
						  + MemoryManager::Read<BYTE>(LocalPlayerArray + 18)) 
						  - (DWORD)Resources::ClientDLL.modBaseAddr;
		#pragma endregion
		#pragma region ENTITY LIST
		DWORD EntityListArray = MemoryManager::FindPatternArr((DWORD)Resources::ClientDLL.modBaseAddr, Resources::ClientDLL.dwSize, "x????xx?xxx", 
															 11, 0x5, 0x0, 0x0, 0x0, 0x0, 
															 0xC1, 0xE9, 0x0, 0x39, 0x48, 0x4);
		m_dwEntityList = (MemoryManager::Read<DWORD>(EntityListArray + 1) 
			             + MemoryManager::Read<BYTE>(EntityListArray + 7)) 
						 - (DWORD)Resources::ClientDLL.modBaseAddr;
		#pragma endregion
		#pragma region VECTOR PUNCH
		DWORD VectorPunchArray = MemoryManager::FindPatternArr((DWORD)Resources::ClientDLL.modBaseAddr, Resources::ClientDLL.dwSize, "xxx????xx????xxxxxx", 
															  19, 0x0F, 0x7E, 0x82, 0x00, 0x00, 0x00, 0x00, 0x8B, 0x82, 
															  0x00, 0x00, 0x00, 0x00, 0x66, 0x0F, 0xD6, 0x45, 0xD0, 0xF3);
		m_vecPunch = MemoryManager::Read<DWORD>(VectorPunchArray + 3);
		#pragma endregion
		#pragma region CROSSHAIR ID
		DWORD CrosshairIDArray = MemoryManager::FindPatternArr((DWORD)Resources::ClientDLL.modBaseAddr, Resources::ClientDLL.dwSize, "xxxxxx????????xx????xx????xxx????xx", 
															  35, 0x56, 0x57, 0x8B, 0xF9, 0xC7, 0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
															  0x00, 0x00, 0x8B, 0x0D, 0x00, 0x00, 0x00, 0x0, 0x81, 0xF9, 0x00, 0x00, 0x00, 
															  0x0, 0x75, 0x07, 0xA1, 0x00, 0x00, 0x00, 0x00, 0xEB, 0x07);
		m_iCrossHairID = MemoryManager::Read<DWORD>(CrosshairIDArray + 6);
		#pragma endregion
		#pragma region SENSITIVITY
		DWORD SensitivityArray = MemoryManager::FindPatternArr((DWORD)Resources::ClientDLL.modBaseAddr, Resources::ClientDLL.dwSize, "xxxx????xx????xxxxxx????xxxxxx?xx", 
															  33, 0x7A, 0x2C, 0x8B, 0x0D, 0, 0, 0, 0, 0x81, 0xF9, 0, 0, 0, 0, 
															  0x75, 0x0A, 0xF3, 0x0F, 0x10, 0x05, 0, 0, 0, 0, 0xEB, 0x0F, 0x8B, 
															  0x01, 0x8B, 0x40, 0, 0xFF, 0xD0);
		m_dwSensitivity = MemoryManager::Read<DWORD>(SensitivityArray + 20) - (DWORD)Resources::ClientDLL.modBaseAddr;
		#pragma endregion
		#pragma region GLOW OBJECT
		DWORD GlowObjectArray = MemoryManager::FindPatternArr((DWORD)Resources::ClientDLL.modBaseAddr, Resources::ClientDLL.dwSize, "x????xxxxxxxx?", 
															 14, 0xB8, 0, 0, 0, 0, 0xC3, 0xCC, 0xCC, 0xCC, 0x55, 0x8B, 0xEC, 0xA1, 0);
		m_dwGlowObject = MemoryManager::Read<DWORD>(GlowObjectArray + 1) - (DWORD)Resources::ClientDLL.modBaseAddr;
		#pragma endregion
		#pragma region VIEW ANGLE
		DWORD ViewAngleArray = MemoryManager::FindPatternArr((DWORD)Resources::EngineDLL.modBaseAddr, Resources::EngineDLL.dwSize, "xx????xxxxx????xxxx????xxx", 
															26, 0x8B, 0x15, 0x00, 0x00, 0x00, 0x00, 0x8B, 0x4D, 0x08, 0x8B, 0x82, 0x00, 0x00, 
															0x00, 0x00, 0x89, 0x01, 0x8B, 0x82, 0x00, 0x00, 0x00, 0x00, 0x89, 0x41, 0x04);
		m_dwViewAngles = MemoryManager::Read<DWORD>(ViewAngleArray + 11);
		#pragma endregion
		#pragma region ENGINE POINTER
		DWORD EnginePointerArray = MemoryManager::FindPatternArr((DWORD)Resources::EngineDLL.modBaseAddr, Resources::EngineDLL.dwSize, "xxxxxxxx????xxxxxxxxxx????xxxx????xxx", 
																37, 0xF3, 0x0F, 0x5C, 0xC1, 0xF3, 0x0F, 0x10, 0x15, 0x0, 0x0, 0x0, 0x0, 0x0F, 0x2F, 0xD0, 0x76, 0x04, 
																0xF3, 0x0F, 0x58, 0xC1, 0xA1, 0x0, 0x0, 0x0, 0x0, 0xF3, 0x0F, 0x11, 0x80, 0x0, 0x0, 0x0, 0x0, 0xD9, 0x46, 0x04);
		m_dwEnginePointer = MemoryManager::Read<DWORD>(EnginePointerArray + 22) - (DWORD)Resources::EngineDLL.modBaseAddr;
		#pragma endregion
		#pragma region FORCE JUMP
		DWORD ForceJumpArray = MemoryManager::FindPatternArr((DWORD)Resources::ClientDLL.modBaseAddr, Resources::ClientDLL.dwSize, "xx????xx????xxxxxxxxxxx", 
															23, 0x89, 0x15, 0x0, 0x0, 0x0, 0x0, 0x8B, 0x15, 0x0, 0x0, 0x0, 
															0x0, 0xF6, 0xC2, 0x3, 0x74, 0x3, 0x83, 0xCE, 0x8, 0xA8, 0x8, 0xBF);
		m_dwForceJump = MemoryManager::Read<DWORD>(ForceJumpArray + 2) - (DWORD)Resources::ClientDLL.modBaseAddr;
		#pragma endregion
	}
	void Offsets::SetOffsetByPatternScan(std::string OffsetName)
	{
		if (OffsetName == "m_dwLocalPlayer")
		{
			#pragma region LOCAL PLAYER
			DWORD LocalPlayerArray = MemoryManager::FindPatternArr(
								(DWORD)Resources::ClientDLL.modBaseAddr, 
								Resources::ClientDLL.modBaseSize, 
								"xxx????xx????xxxxx?", 
								19, 0x8D, 0x34, 0x85, 0x0, 0x0, 0x0, 0x0, 0x89, 0x15,
								0x0, 0x0, 0x0, 0x0, 0x8B, 0x41, 0x8, 0x8B, 0x48, 0x0);
			m_dwLocalPlayer = (MemoryManager::Read<DWORD>(LocalPlayerArray + 3)
						  +	 MemoryManager::Read<BYTE>(LocalPlayerArray + 18)) 
						  -	(DWORD)Resources::ClientDLL.modBaseAddr;
		#pragma endregion
		}
		else if (OffsetName == "m_dwEntityList")
		{
			#pragma region ENTITY LIST
			DWORD EntityListArray = MemoryManager::FindPatternArr((DWORD)Resources::ClientDLL.modBaseAddr, Resources::ClientDLL.dwSize, "x????xx?xxx", 
															 11, 0x5, 0x0, 0x0, 0x0, 0x0, 
															 0xC1, 0xE9, 0x0, 0x39, 0x48, 0x4);
			m_dwEntityList = (MemoryManager::Read<DWORD>(EntityListArray + 1) 
			             + MemoryManager::Read<BYTE>(EntityListArray + 7)) 
						 - (DWORD)Resources::ClientDLL.modBaseAddr;
			#pragma endregion
		}
		else if (OffsetName == "m_vecPunch")
		{
			#pragma region VECTOR PUNCH
			DWORD VectorPunchArray = MemoryManager::FindPatternArr((DWORD)Resources::ClientDLL.modBaseAddr, Resources::ClientDLL.dwSize, "xxx????xx????xxxxxx", 
															  19, 0x0F, 0x7E, 0x82, 0x00, 0x00, 0x00, 0x00, 0x8B, 0x82, 
															  0x00, 0x00, 0x00, 0x00, 0x66, 0x0F, 0xD6, 0x45, 0xD0, 0xF3);
			m_vecPunch = MemoryManager::Read<DWORD>(VectorPunchArray + 3);
			#pragma endregion
		}
		else if (OffsetName == "m_iCrossHairID")
		{
			#pragma region CROSSHAIR ID
			DWORD CrosshairIDArray = MemoryManager::FindPatternArr((DWORD)Resources::ClientDLL.modBaseAddr, Resources::ClientDLL.dwSize, "xxxxxx????????xx????xx????xxx????xx", 
																  35, 0x56, 0x57, 0x8B, 0xF9, 0xC7, 0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
																  0x00, 0x00, 0x8B, 0x0D, 0x00, 0x00, 0x00, 0x0, 0x81, 0xF9, 0x00, 0x00, 0x00, 
																  0x0, 0x75, 0x07, 0xA1, 0x00, 0x00, 0x00, 0x00, 0xEB, 0x07);
			m_iCrossHairID = MemoryManager::Read<DWORD>(CrosshairIDArray + 6);
			#pragma endregion
		}
		else if (OffsetName == "m_dwSensitivity")
		{
			#pragma region SENSITIVITY
			DWORD SensitivityArray = MemoryManager::FindPatternArr((DWORD)Resources::ClientDLL.modBaseAddr, Resources::ClientDLL.dwSize, "xxxx????xx????xxxxxx????xxxxxx?xx", 
																  33, 0x7A, 0x2C, 0x8B, 0x0D, 0, 0, 0, 0, 0x81, 0xF9, 0, 0, 0, 0, 
																  0x75, 0x0A, 0xF3, 0x0F, 0x10, 0x05, 0, 0, 0, 0, 0xEB, 0x0F, 0x8B, 
																  0x01, 0x8B, 0x40, 0, 0xFF, 0xD0);
			m_dwSensitivity = MemoryManager::Read<DWORD>(SensitivityArray + 20) - (DWORD)Resources::ClientDLL.modBaseAddr;
			#pragma endregion
		}
		else if (OffsetName == "m_dwGlowObject")
		{
			#pragma region GLOW OBJECT
			DWORD GlowObjectArray = MemoryManager::FindPatternArr((DWORD)Resources::ClientDLL.modBaseAddr, Resources::ClientDLL.dwSize, "x????xxxxxxxx?", 
																 14, 0xB8, 0, 0, 0, 0, 0xC3, 0xCC, 0xCC, 0xCC, 0x55, 0x8B, 0xEC, 0xA1, 0);
			m_dwGlowObject = MemoryManager::Read<DWORD>(GlowObjectArray + 1) - (DWORD)Resources::ClientDLL.modBaseAddr;
			#pragma endregion
		}
		else if (OffsetName == "m_dwViewAngles")
		{
			#pragma region VIEW ANGLE
			DWORD ViewAngleArray = MemoryManager::FindPatternArr((DWORD)Resources::EngineDLL.modBaseAddr, Resources::EngineDLL.dwSize, "xx????xxxxx????xxxx????xxx", 
																26, 0x8B, 0x15, 0x00, 0x00, 0x00, 0x00, 0x8B, 0x4D, 0x08, 0x8B, 0x82, 0x00, 0x00, 
																0x00, 0x00, 0x89, 0x01, 0x8B, 0x82, 0x00, 0x00, 0x00, 0x00, 0x89, 0x41, 0x04);
			m_dwViewAngles = MemoryManager::Read<DWORD>(ViewAngleArray + 11);
			#pragma endregion
		}
		else if (OffsetName == "m_dwEnginePointer")
		{
			#pragma region ENGINE POINTER
			DWORD EnginePointerArray = MemoryManager::FindPatternArr((DWORD)Resources::EngineDLL.modBaseAddr, Resources::EngineDLL.dwSize, "xxxxxxxx????xxxxxxxxxx????xxxx????xxx", 
																37, 0xF3, 0x0F, 0x5C, 0xC1, 0xF3, 0x0F, 0x10, 0x15, 0x0, 0x0, 0x0, 0x0, 0x0F, 0x2F, 0xD0, 0x76, 0x04, 
																0xF3, 0x0F, 0x58, 0xC1, 0xA1, 0x0, 0x0, 0x0, 0x0, 0xF3, 0x0F, 0x11, 0x80, 0x0, 0x0, 0x0, 0x0, 0xD9, 0x46, 0x04);
			m_dwEnginePointer = MemoryManager::Read<DWORD>(EnginePointerArray + 22) - (DWORD)Resources::EngineDLL.modBaseAddr;
			#pragma endregion
		}
		else if (OffsetName == "m_dwForceJump")
		{
			#pragma region FORCE JUMP
			DWORD ForceJumpArray = MemoryManager::FindPatternArr((DWORD)Resources::ClientDLL.modBaseAddr, Resources::ClientDLL.dwSize, "xx????xx????xxxxxxxxxxx", 
															23, 0x89, 0x15, 0x0, 0x0, 0x0, 0x0, 0x8B, 0x15, 0x0, 0x0, 0x0, 
															0x0, 0xF6, 0xC2, 0x3, 0x74, 0x3, 0x83, 0xCE, 0x8, 0xA8, 0x8, 0xBF);
			m_dwForceJump = MemoryManager::Read<DWORD>(ForceJumpArray + 2) - (DWORD)Resources::ClientDLL.modBaseAddr;
			#pragma endregion
		}
	}
#pragma endregion
}