#pragma once
namespace game
{
	// Reversed from UI_GetFontHandle 
	enum Fonts
	{
		Normal = 1,
		Big = 2,
		Small = 3,
		Console = 5,
		ExtraBig = 6
	};

	constexpr const char* kBigDevFont = "fonts/bigdevfont";
	constexpr const char* kBigFont = "fonts/bigfont";
	constexpr const char* kBoldFont = "fonts/boldfont";
	constexpr const char* kClanFont = "fonts/clanfont";
	constexpr const char* kConsoleFont = "fonts/consolefont";
	constexpr const char* kExtraBigFont = "fonts/extrabigfont";
	constexpr const char* kNormalFont = "fonts/normalfont";
	constexpr const char* kSmallDevFont = "fonts/smalldevfont";
	constexpr const char* kSmallFont = "fonts/smallfont";

	int Cbuf_AddText(int localClientNum, const char* text);
	void CG_GameMessage(int localClientNum, const char* msg);
	void* CL_RegisterFont(const char* fontName, int imageTrack);
	int Com_sprintf(char* dst, int size, const char* fmt, ...);
	void* Material_RegisterHandle(const char* name, int imageTrack);
	void UI_DrawText(void* scrPlace, const char* text, int maxChars, void* font, float x, float y, int horzAlign, int vertAlign, float scale, const float* color, int style);
	void UI_DrawHandlePic(void* scrPlace, float x, float y, float w, float h, int horzAlign, int vertAlign, const float* color, void* material);
	int UI_TextHeight(void* font, float scale);
	void* UI_GetFontHandle(void* scrPlace, int fontEnum, float scale);
	void* scrPlaceView(int localClientNum);
}