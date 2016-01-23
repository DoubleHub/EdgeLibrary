// CHEntityManager.h
// Declares CHEntity class
 
#pragma once
// INCLUDE SPACE ====================================
#include "stdafx.h"
// ==================================================
 
namespace EdgeLibrary
{
    //TODO: Add comments for everything
 
    class CHEntity
    {
    public:
        #pragma region EMPTY CTOR AND DTOR
        CHEntity(){}
        ~CHEntity(){}
        #pragma endregion
 
        #pragma region CHENTITY FUNCTIONS
 
        static DWORD GetEntityBase();
 
        static int GetHealth();
 
        static int GetTeam();
 
        static Vector3 GetVecOrigin();
 
        static Vector3 GetEyePos();
 
        static DWORD GetBoneBase();
 
        #pragma endregion
    };
 
}