// OffsetManager.h
// Declares Offsets class

#pragma once
// INCLUDE SPACE =========================================
#include "stdafx.h"
// =======================================================

namespace EdgeLibrary
{
	//Contains various CSGO offsets
	class Offsets
	{
	public:
		#pragma region EMPTY CTOR AND DTOR
		Offsets()
		{
		}
		~Offsets()
		{
		}
		#pragma endregion
		#pragma region OFFSETS
		static DWORD m_fAccuracyPenalty;
		static DWORD m_nForceBone;
		static DWORD m_iState;
		static DWORD m_iClip1;
		static DWORD m_flNextPrimaryAttack;
		static DWORD m_bCanReload;
		static DWORD m_iPrimaryAmmoType;
		static DWORD m_iWeaponID;
		static DWORD m_zoomLevel;
		static DWORD m_bSpotted;
		static DWORD m_bSpottedByMask;
		static DWORD m_hOwnerEntity;
		static DWORD m_vecOrigin;
		static DWORD m_iTeamNum;
		static DWORD m_flFlashMaxAlpha;
		static DWORD m_flFlashDuration;
		static DWORD m_iGlowIndex;
		static DWORD m_angEyeAngles;
		static DWORD m_iAccount;
		static DWORD m_ArmorValue;
		static DWORD m_bGunGameImmunity;
		static DWORD m_iShotsFired;
		static DWORD CSPlayerResource;
		static DWORD m_iCompetitiveRanking;
		static DWORD m_iCompetitiveWins;
		static DWORD m_iKills;
		static DWORD m_iAssists;
		static DWORD m_iDeaths;
		static DWORD m_iPing;
		static DWORD m_iScore;
		static DWORD m_szClan;
		static DWORD m_lifeState;
		static DWORD m_fFlags;
		static DWORD m_iHealth;
		static DWORD m_hLastWeapon;
		static DWORD m_hMyWeapons;
		static DWORD m_hActiveWeapons;
		static DWORD m_Local;
		static DWORD m_vecViewOffset;
		static DWORD m_nTickBase;
		static DWORD m_vecVelocity;
		static DWORD m_szLastPlaceName;
		static DWORD m_vecPunch;
		static DWORD m_iCrossHairID;
		static DWORD m_dwModel;
		static DWORD m_dwIndex;
		static DWORD m_dwBoneMatrix;
		static DWORD m_bMoveType;
		static DWORD m_bDormant;
		static DWORD m_dwClientState;
		static DWORD m_dwLocalPlayerIndex;
		static DWORD m_dwInGame;
		static DWORD m_dwMaxPlayer;
		static DWORD m_dwMapDirectory;
		static DWORD m_dwMapName;
		static DWORD m_dwPlayerInfo;
		static DWORD m_dwViewAngles;
		static DWORD m_dwViewMatrix;
		static DWORD m_dwEnginePosition;
		static DWORD m_dwRadarBase;
		static DWORD m_dwRadarBasePointer;
		static DWORD m_dwLocalPlayer;
		static DWORD m_dwEntityList;
		static DWORD m_dwWeaponTable;
		static DWORD m_dwWeaponTableIndex;
		static DWORD m_dwInput;
		static DWORD m_dwGlobalVars;
		static DWORD m_dwGlowObject;
		static DWORD m_dwForceJump;
		static DWORD m_dwForceAttack;
		static DWORD m_dwSensitivity;
		static DWORD m_dwMouseEnable;
		static DWORD m_dwEntityLoopDistance;
		static DWORD m_dwEnginePointer;
		#pragma endregion
		//Reads offsets from a give INI file
		static void Offsets::GetOffsetsByFile(LPCSTR FilePath);
		//Reads offsets with Pattern Scanning method
		static void Offsets::GetOffsetsByPatternScan();
		//Read a certain offset with Pattern Scanning Method
		static void Offsets::SetOffsetByPatternScan(std::string OffsetName);
	};
}