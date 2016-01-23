// ClientManager.h
// Declares Client class

#pragma once
// INCLUDE SPACE =========================================
#include "stdafx.h"
// =======================================================

namespace EdgeLibrary
{
	//Contains various functions around the Client
	class Client
	{
	public:
		#pragma region EMPTY CTOR AND DTOR
		Client(){}
		~Client(){}
		#pragma endregion
		#pragma region CLIENT FUNCTIONS

		//Returns the current state of +attack as int
		static int GetAttack();

		//Returns the current state of +forward as int
		static int GetMoveForward();

		//Returns the current state of +jump as int
		static int GetJump();

		//Returns the GlowPointer as int
		static DWORD GetGlowPointer();

		//Sets +attack to a given value, returns true if it succeeds, returns false if it fails
		static bool SetAttack(int Value);

		//Sets +forward to a given value, returns true if it succeeds, returns false if it fails
		static bool SetMoveForward(int Value);

		//Sets +jump to a given value, returns true if it succeeds, returns false if it fails
		static bool SetJump(int Value);

		#pragma endregion	
	};
}