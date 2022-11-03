#pragma once
namespace game
{
	int Cbuf_AddText(int localClientNum, const char* text);
	int UI_DrawText(void* scrPlace, const char* text, int maxChars, void* font, float x, float y, int horzAlign, int vertAlign, float scale, const float* color, int style);
	void* UI_GetFontHandle(void* scrPlace, int fontEnum, float scale);
	void* scrPlaceView(int localClientNum);
}