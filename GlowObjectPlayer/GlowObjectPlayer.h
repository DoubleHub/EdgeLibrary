// GlowObjectPlayer.h
// Declares GlowObjectPlayer struct

#pragma once
#include "stdafx.h"

namespace EdgeLibrary
{
	struct GlowObjectPlayer_t
	{
		DWORD pEntity;
		float r,g,b,a;
		uint8_t unk1[16];
		bool RenderWhenOccluded;
		bool RenderWhenUnoccluded;
		bool FullBloom;
		uint8_t unk2[14];
	};
}