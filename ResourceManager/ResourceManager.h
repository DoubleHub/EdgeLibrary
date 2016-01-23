// ResourceManager.h
// Declares Resources class

#pragma once
// INCLUDE SPACE =========================================
#include "stdafx.h"
// =======================================================

namespace EdgeLibrary
{
	//Resources class contains various resources
	class Resources
	{
	public:
		#pragma region EMPTY CTOR AND DTOR
		Resources(){}
		~Resources(){}
		#pragma endregion
		#pragma region RESOURCES
		//Holds BaseAddress of client.dll module
		static MODULEENTRY32 ClientDLL;
		//Holds BaseAddress of engine.dll module
		static MODULEENTRY32 EngineDLL;
		#pragma endregion
	};
}