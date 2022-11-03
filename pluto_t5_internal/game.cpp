#include "pch.h"

namespace game
{
	int Cbuf_AddText(int localClientNum, const char* text)
	{
		// Returned integer has something to do with an overflow?
		// Not sure what it is exactly
		uint32_t address = addresses::Cbuf_AddtextAddr;
		int result = ((int(__cdecl*)(int, const char*))address)(localClientNum, text);
		return result;
	}

	void* scrPlaceView(int localClientNum)
	{
		// scrPlaceView[localClientNum]
		return (void*)(120 * localClientNum + addresses::scrPlaceViewAddr);
	}

	int UI_DrawText(void* scrPlace, const char* text, int maxChars, void* font, float x, float y, int horzAlign, int vertAlign, float scale, const float* color, int style)
	{
		uint32_t address = addresses::UI_DrawTextAddr;
		int result = ((int(__cdecl*)(void*, const char*, int, void*, float, float, int, int, float, const float*, int))address)(scrPlace, text, maxChars, font, x, y, horzAlign, vertAlign, scale, color, style);
		return result;
	}

	void* UI_GetFontHandle(void* scrPlace, int fontEnum, float scale)
	{
		uint32_t address = addresses::UI_GetFontHandleAddr;
		void* result = ((void* (__cdecl*)(void*, int, float))address)(scrPlace, fontEnum, scale);
		return result;
	}
}