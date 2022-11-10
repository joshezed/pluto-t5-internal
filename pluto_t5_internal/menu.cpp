#include "pch.h"
#include "menu.h"
#include "game.h"
#include "options.h"

#define OPTS_LEN(arr, opt) (sizeof(arr) / sizeof(opt))

namespace menu
{
	void* scrPlace;
	void* option_font;
	int option_font_height;
	void* scroller_material;

	float text_x = 0.f;
	float text_y = 0.f;
	float scroller_x = 0.f;
	float scroller_y = 0.f;
	float scroller_color[] = { 1.f, 0.f, 0.f, 1.f }; // (RGBA / 255)
	float option_font_scale = 1.f;
	float option_color[] = { 1.f, 1.f, 1.f, 1.f };

	bool open = true;
	Submenu current_menu = Submenu::Root;
	Submenu prev_menu = Submenu::Root;
	size_t selection_index[Submenu::Count] = { 0 };
	size_t draw_index = 0;

	Option* options[] = {
		new Option(Root, "Test Option"),
		new Option(Root, "Test Option 2"),
		new Option(Root, "Test Option 3"),
		new CmdOption(Main, "Command Option", "say hello world!"),
		new Option(Main, "Test in Main")
	};

	void Initialize()
	{
		scrPlace = game::scrPlaceView(0);
		option_font = game::CL_RegisterFont(game::kNormalFont, 0);
		option_font_height = game::UI_TextHeight(option_font, option_font_scale);
		scroller_material = game::Material_RegisterHandle("white", 0);

		game::CG_GameMessage(0, "PlutoT5Internal loaded!");
	}

	void Terminate()
	{
		for (size_t i = 0; i < OPTS_LEN(options, Option*); i++)
			delete options[i];
	}

	void Update()
	{
		if (GetAsyncKeyState('I') & 0x01)
		{
			if (current_menu == Root)
				current_menu = Main;
			else
				current_menu = Root;
		}
	}

	void Draw()
	{
		if (!open)
			return;

		game::UI_DrawHandlePic(scrPlace, scroller_x, scroller_y, 100.f, (float)option_font_height, 0, 0, scroller_color, scroller_material);
		
		draw_index = 0;
		for (size_t i = 0; i < OPTS_LEN(options, Option*); i++)
		{
			if (options[i]->menu != current_menu)
				continue;
			DrawOption(options[i]->text);
		}
	}

	void DrawOption(const char* text)
	{
		void* font = option_font;
		int font_height = option_font_height;
		float font_scale = option_font_scale;

		game::UI_DrawText(scrPlace, text, 255, font, text_x, text_y + font_height + (draw_index * font_height), 0, 0, font_scale, option_color, 0);
		draw_index++;
	}
}