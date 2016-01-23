// ResourceManager.cpp
// Defines Resources class

// INCLUDE SPACE =========================================
#include "stdafx.h"
// =======================================================

namespace EdgeLibrary
{
	//Holds BaseAddress of client.dll module
	MODULEENTRY32 Resources::ClientDLL;
	//Holds BaseAddress of engine.dll module
	MODULEENTRY32 Resources::EngineDLL;
}