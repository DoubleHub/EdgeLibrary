// EntityManager.h
// Declares Entity class

#pragma once
// INCLUDE SPACE =========================================
#include "stdafx.h"
// =======================================================

namespace EdgeLibrary
{
	//Contains various functions around an Entity
	class Entity
	{
	public:
		#pragma region EMPTY CTOR AND DTOR
		Entity(){}
		~Entity(){}
		#pragma endregion
		#pragma region ENTITY FUNCTIONS

		//Returns the BaseAddress of an Entity by passing the specific ID of that Entity. Returns DWORD
		static DWORD GetEntityBaseAddress(int Index);

		//Returns the ID of the Entity currently in the middle of the Crosshair of LocalPlayer as DWORD
		static DWORD GetEntityCrosshair();

		//Returns the eye position of a given Entity by Index as Vector3
		static Vector3 GetEyePos(int Index);

		//Returns the TeamID of a given Entity by Index as int
		static int GetTeam(int Index);

		//Returns the current Health of a given Entity by Index as int
		static int GetHealth(int Index);

		//Returns the current dormant state of a given Entity by Index as bool
		static bool GetDormant(int Index);

		//Returns the current bSpotted state of a given Entity by Index as bool
		static bool GetbSpotted(int Index);

		//Returns the distance to a given Entity by Index as float
		static float GetDistanceFromEntity(int Index);

		//Returns the BoneBase of a given Entity by Index as DWORD
		static DWORD GetBoneBase(int Index);

		//Returns the FeetPosition of a given Entity by Index as Vector3
		static Vector3 GetFeetPosition(int Index);

		//Returns the GlowIndex of a given Entity by Index as int
		static int GetGlowIndex(int Index);

		//Returns if a given Entity is alive as bool
		static bool GetAliveState(int Index);

		//Sets bSpotted of a given Entity by Index to a given value, returns true if it succeeds, returns false if it fails
		static bool SetbSpotted(int Index, int Value);

		#pragma endregion
	};
}