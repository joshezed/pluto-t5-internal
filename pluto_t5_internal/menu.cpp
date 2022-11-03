#include "pch.h"
#include "menu.h"
#include "game.h"

namespace menu
{
	void Update()
	{
		// TODO 
	}

	void Draw()
	{
		void* scrPlace = game::scrPlaceView(0);
		void* font = game::UI_GetFontHandle(scrPlace, 3, 1.f);
		const float color[] = { 1.f, 1.f, 1.f, 1.f };
		game::UI_DrawText(scrPlace, "Hello, world!", 256, font, 100.f, 100.f, 0, 0, 1.f, color, 0);
	}
}