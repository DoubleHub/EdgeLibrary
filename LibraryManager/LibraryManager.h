// LibraryManager.h
// Declares LibraryManager class

#pragma once
// INCLUDE SPACE =========================================
#include "stdafx.h"
#include "Vector2.h"
#include "Vector3.h"
// =======================================================

namespace EdgeLibrary
{
	class LibraryManager
	{
	public:
		//Setup EdgeLibrary
		static int Setup(std::string Hackname);

		#pragma region USEFUL FUNCTIONS

		//Converts a const char* to LPCWSTR
		static wchar_t* convertCharArrayToLPCWSTR(const char* charArray);

		//Returns normalized Angles to prevent "Untrusted" bans as Vector3
		static Vector3 NormalizeAngle(Vector3 Angle);

		//Returns a calculated Angle between Source and Destination as Vector3
		static Vector3 CalculateAngle(Vector3 Source, Vector3 Destination);

		//Returns the 3D Distance to an Entity by Index as float
		static float Get3DDistance(int Index);

		//Returns the 3D Distance from a Vector3 to a Vector3 as float
		static float Get3DDistance(Vector3 Source, Vector3 Destination);

		//Translates 3D coordinates into 2D coordinates, returns true if it succeeds, returns false if it fails
		static bool WorldToScreen(Vector3 ThreeDCoordinates, Vector2 &TwoDCoordinates);

		//Returns the distance from an Entity to the Crosshair ( Use 2D Coordinates ! ) as float
		static float GetDistanceFromCrosshair(Vector2 EntityCoordinates);

		//Checks if the given Angle contains a NaN value
		static bool isnanf(Vector3 Angle);

		//Emulate a mouse click with given float delays
		static void mouse_click(float delay_before, float delay_between, float delay_after);

		#pragma endregion
	};
}