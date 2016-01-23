// LibraryManager.cpp
// Defines LibraryManager class

// INCLUDE SPACE =========================================
#include "stdafx.h"
#include "Vector2.h"
#include "Vector3.h"
// =======================================================

struct WorldToScreenMatrix_t
{
	float flMatrix[4][4];
};

namespace EdgeLibrary
{

	//Setup EdgeLibrary
	int LibraryManager::Setup(std::string Hackname)
	{
		if (Log::InitDirectories("C:\\", ("\\"+Hackname)))
		{
			std::string LogPath = "C:\\" + Hackname;
			std::string LogFilePath = LogPath + "\\Log.txt";
			if (Log::InitializeNewLogSection(Hackname, LogFilePath))
			{
				if (!MemoryManager::AttachProcess("csgo.exe"))
					return -6;

				if (!Log::NewLog("CSGO found!", LogFilePath))
					return -3;

				Resources::ClientDLL = MemoryManager::AttachModule("client.dll");
				Resources::EngineDLL = MemoryManager::AttachModule("engine.dll");

				if ((DWORD)Resources::ClientDLL.modBaseAddr == 0x0)
					return -4;
				if ((DWORD)Resources::EngineDLL.modBaseAddr == 0x0)
					return -5;
			}
			else
				return -2;
		}
		else
			return -1;

		return 1;
	}

	#pragma region USEFUL FUNCTIONS

	//Converts a const char* to LPCWSTR
	wchar_t* LibraryManager::convertCharArrayToLPCWSTR(const char* charArray)
	{
		wchar_t* wString=new wchar_t[4096];
		MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
		return wString;
	}

	//Returns normalized Angles to prevent "Untrusted" bans as Vector3
	Vector3 LibraryManager::NormalizeAngle(Vector3 Angle)
	{
		Vector3 vec = Angle;

		if (vec.x > 89.0f && vec.x <= 180.0f)
			vec.x = 89.0f;
		while (vec.x > 180.f)
			vec.x -= 360.f;
		while (vec.x < -89.0f)
			vec.x = -89.0f;
		while (vec.y > 180.f)
			vec.y -= 360.f;
		while (vec.y < -180.f)
			vec.y += 360.f;

		vec.z = 0;
		return vec;
	}

	//Returns a calculated Angle between Source and Destination as Vector3
	Vector3 LibraryManager::CalculateAngle(Vector3 Source, Vector3 Destination)
	{
		Vector3 angles;
		Vector3 delta;
		delta.x = (Source.x - Destination.x);
		delta.y = (Source.y - Destination.y);
		delta.z = (Source.z - Destination.z);

		double hyp = sqrt(delta.x * delta.x + delta.y * delta.y);
		angles.x = (float)(atanf(delta.z / hyp) * 57.295779513082f);
		angles.y = (float)(atanf(delta.y / delta.x) * 57.295779513082f);

		angles.z = 0.0f;
		if (delta.x >= 0.0) { angles.y += 180.0f; }
		return angles;
	}

	//Returns the 3D Distance to an Entity by Index as float
	float LibraryManager::Get3DDistance(int Index)
	{
		Vector3 PlayerCoordinates = LocalPlayer::GetVecOrigin();
		Vector3 EntityCoordinates = Entity::GetFeetPosition(Index);

		return sqrt(
			pow(double(EntityCoordinates.x - PlayerCoordinates.x), 2.0) +
			pow(double(EntityCoordinates.y - PlayerCoordinates.y), 2.0) +
			pow(double(EntityCoordinates.z - PlayerCoordinates.z), 2.0));
	}

	//Returns the 3D Distance from a Vector3 to a Vector3 as float
	float LibraryManager::Get3DDistance(Vector3 Source, Vector3 Destination)
	{
		return sqrt(
			pow(double(Destination.x - Source.x), 2.0) +
			pow(double(Destination.y - Source.y), 2.0) +
			pow(double(Destination.z - Source.z), 2.0));
	}

	//Translates 3D coordinates into 2D coordinates, returns true if it succeeds, returns false if it fails
	//Takes the 2D coordinates into the second parameter address
	bool LibraryManager::WorldToScreen(Vector3 ThreeDCoordinates, Vector2 &TwoDCoordinates)
	{
		RECT rc;
		HWND hWnd = FindWindow(LibraryManager::convertCharArrayToLPCWSTR("Valve001"), NULL);
		GetWindowRect(hWnd, &rc);

		WorldToScreenMatrix_t WorldToScreenMatrix;
		WorldToScreenMatrix = MemoryManager::Read<WorldToScreenMatrix_t>((DWORD)Resources::ClientDLL.modBaseAddr + Offsets::m_dwViewMatrix);
		float w = 0.0f;

		TwoDCoordinates.x = WorldToScreenMatrix.flMatrix[0][0] * ThreeDCoordinates.x + WorldToScreenMatrix.flMatrix[0][1] * ThreeDCoordinates.y + WorldToScreenMatrix.flMatrix[0][2] * ThreeDCoordinates.z + WorldToScreenMatrix.flMatrix[0][3];
		TwoDCoordinates.y = WorldToScreenMatrix.flMatrix[1][0] * ThreeDCoordinates.x + WorldToScreenMatrix.flMatrix[1][1] * ThreeDCoordinates.y + WorldToScreenMatrix.flMatrix[1][2] * ThreeDCoordinates.z + WorldToScreenMatrix.flMatrix[1][3];
		w = WorldToScreenMatrix.flMatrix[3][0] * ThreeDCoordinates.x + WorldToScreenMatrix.flMatrix[3][1] * ThreeDCoordinates.y + WorldToScreenMatrix.flMatrix[3][2] * ThreeDCoordinates.z + WorldToScreenMatrix.flMatrix[3][3];

		if (w < 0.01f)
			return false;

		float invw = 1.0f / w;
		TwoDCoordinates.x *= invw;
		TwoDCoordinates.y *= invw;

		int width = (int)(rc.right - rc.left);
		int height = (int)(rc.bottom - rc.top);

		float x = width / 2;
		float y = height / 2;

		x += 0.5 * TwoDCoordinates.x * width + 0.5;
		y -= 0.5 * TwoDCoordinates.y * height + 0.5;

		TwoDCoordinates.x = x + rc.left;
		TwoDCoordinates.y = y + rc.top;

		return true;
	}

	//Returns the distance from an Entity to the Crosshair ( Use 2D Coordinates ! ) as float
	float LibraryManager::GetDistanceFromCrosshair(Vector2 EntityCoordinates)
	{
		Vector3 myscreen = { (float)GetSystemMetrics(SM_CXSCREEN) / 2, (float)GetSystemMetrics(SM_CYSCREEN) / 2, 0 };
		return sqrt(pow(double(EntityCoordinates.x - myscreen.x), 2.0) + pow(double(EntityCoordinates.y - myscreen.y), 2.0));
	}

	//Checks if the given Angle contains a NaN value
	bool LibraryManager::isnanf(Vector3 Angle)
	{
		if (Angle.x != Angle.x || Angle.y != Angle.y || Angle.z != Angle.z)
			return true;
		return false;
	}

	//Emulate a mouse click with given float delays
	void LibraryManager::mouse_click(float delay_before, float delay_between, float delay_after)
	{
		Sleep(delay_before);
		mouse_event(MOUSEEVENTF_LEFTDOWN,NULL,NULL,NULL,NULL);
		Sleep(delay_between);
		mouse_event(MOUSEEVENTF_LEFTUP,NULL,NULL,NULL,NULL);
		Sleep(delay_after);
	}

	#pragma endregion

}