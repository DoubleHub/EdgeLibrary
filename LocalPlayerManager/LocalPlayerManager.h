// LocalPlayerManager.h
// Declares LocalPlayer class

#pragma once
// INCLUDE SPACE =========================================
#include "stdafx.h"
#include "Vector3.h"
// =======================================================

namespace EdgeLibrary
{
	//Contains various functions around the LocalPlayer
	class LocalPlayer
	{
	public:
		#pragma region EMPTY CTOR AND DTOR
		LocalPlayer()
		{
		}
		~LocalPlayer()
		{
		}
		#pragma endregion	
		
		#pragma region LOCALPLAYER FUNCTIONS

		//Returns the Base Address of LocalPlayer as DWORD
		static DWORD GetLocalPlayerBaseAddress();

		//Returns the ID of the crosshair
		static int GetCrosshairID();

		//Returns the FeetPosition of LocalPlayer as Vector3
		static Vector3 GetVecOrigin();

		//Returns the current Team of LocalPlayer as int
		static int GetTeam();
		
		//Returns the current Health of LocalPlayer as int
		static int GetHealth();

		//Returns the current FlashMaxAlpha of LocalPlayer as float
		static float GetFlashMaxAlpha();

		//Returns the current EyePosition of LocalPlayer as Vector3
		static Vector3 GetEyePos();

		//Returns the current Armor of LocalPlayer as int
		static int GetArmor();

		//Returns the number of shots fired in a single spray until LocalPlayer lets go of +attack as int
		static int GetShotsFired();

		//Returns the Flags of LocalPlayer as BYTE
		static BYTE GetFlags();

		//Returns the current ViewAngles of LocalPlayer as Vector3
		static Vector3 GetViewAngles();

		//Returns the current Velocity of LocalPlayer as Vector3
		static Vector3 GetVecVelocity();

		//Returns the current PunchAngles of LocalPlayer as Vector3
		static Vector3 GetVecPunch();

		//Returns ClientState (some people call it EnginePointer) as DWORD
		static DWORD GetClientState();

		//Returns the current sensitivity of LocalPlayer as float
		static float GetSens();

		//Sets FlashMaxAlpha of LocalPlayer to a given value, returns true if it succeeds, returns false if it fails
		static bool SetFlashMaxAlpha(float Value);

		//Sets the ViewAngles of LocalPlayer to a given Vector3, returns true if it succeeds, returns false if it fails
		static bool SetViewAngles(Vector3 AnglesToSet);

		//Sets the Sensitivity of LocalPlayer to a given float, returns true if it suceeds, returns false if it fails
		static bool SetSens(float Sens);

		#pragma endregion
	};
}