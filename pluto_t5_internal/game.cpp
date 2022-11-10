#include "pch.h"
#include "game.h"

namespace game
{
	int Cbuf_AddText(int localClientNum, const char* text)
	{
		// Returned integer has something to do with an overflow?
		// Not sure what it is exactly
		uint32_t address = addresses::Cbuf_Addtext;
		int result = ((int(__cdecl*)(int, const char*))address)(localClientNum, text);
		return result;
	}

	void CG_GameMessage(int localClientNum, const char* msg)
	{
		uint32_t address = addresses::CG_GameMessage;
		// Third argument is some sort of flag. It's always 0 in the original executable
		// but has different values in the modified one.
		((void(__cdecl*)(int, const char*, int))address)(localClientNum, msg, 0);
	}

	void* CL_RegisterFont(const char* fontName, int imageTrack)
	{
		// NOTE: UI_GetFontHandle returns the font pointers this function generates
		// and discards the scrPlace and scale arguments when provided with 
		// specific fontEnum values.
		// Therefore, we can call this function directly to access even more fonts.
		// Also, imageTrack only matters when the useFastFile DVAR is enabled.
		// So, pray that it's enabled so we can ignore that argument lol.
		uint32_t address = addresses::CL_RegisterFont;
		void* font = ((void* (__cdecl*)(const char*, int))address)(fontName, imageTrack);
		return font;
	}

	// Since we can't use the standard lib, we will yoink funcs from the game :)
	int Com_sprintf(char* dst, int size, const char* fmt, ...)
	{
		uint32_t address = addresses::Com_sprintf;
		int result = ((int(__cdecl*)(char*, int, const char*, ...))address)(dst, size, fmt);
		// Returned int is the same as vsnprintf result 
		return result;
	}

	void* Material_RegisterHandle(const char* name, int imageTrack)
	{
		uint32_t address = addresses::Material_RegisterHandle;
		void* material = ((void* (__cdecl*)(const char*, int))address)(name, imageTrack);
		return material;
	}

	void* scrPlaceView(int localClientNum)
	{
		// scrPlaceView[localClientNum]
		return (void*)(120 * localClientNum + addresses::scrPlaceView);
	}

	void UI_DrawText(void* scrPlace, const char* text, int maxChars, void* font, float x, float y, int horzAlign, int vertAlign, float scale, const float* color, int style)
	{
		// horzAlign and vertAlign have values between and including 0 and 10.
		// I'd have to test each one to see what they do.
		uint32_t address = addresses::UI_DrawText;
		((void(__cdecl*)(void*, const char*, int, void*, float, float, int, int, float, const float*, int))address)(scrPlace, text, maxChars, font, x, y, horzAlign, vertAlign, scale, color, style);
	}

	void UI_DrawHandlePic(void* scrPlace, float x, float y, float w, float h, int horzAlign, int vertAlign, const float* color, void* material)
	{
		uint32_t address = addresses::UI_DrawHandlePic;
		((void(__cdecl*)(void*, float, float, float, float, int, int, const float*, void*))address)(scrPlace, x, y, w, h, horzAlign, vertAlign, color, material);
	}

	int UI_TextHeight(void* font, float scale)
	{
		uint32_t address = addresses::UI_TextHeight;
		int text_height = ((int(__cdecl*)(void*, float))address)(font, scale);
		return text_height;
	}

	void* UI_GetFontHandle(void* scrPlace, int fontEnum, float scale)
	{
		uint32_t address = addresses::UI_GetFontHandle;
		void* result = ((void* (__cdecl*)(void*, int, float))address)(scrPlace, fontEnum, scale);
		return result;
	}
}