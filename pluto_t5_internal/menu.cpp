#include "pch.h"
#include "menu.h"
#include "game.h"
#include "options.h"

namespace menu
{
	bool open = true;
	Submenu current_menu = Submenu::Root;
	Submenu prev_menu = Submenu::Root;
	int opt_index[Submenu::Count] = { 0 };
	Option* options;
	size_t options_len = 0;

	Option root_options[] = {
		Option("Hello, world!"),
		Option("This is a test."),
		Option("Last one!"),
		CmdOption("Command Option! (noclip)", "noclip")
	};

	Option main_options[] = {
		Option("Main options test!"),
		Option("Hope this works...")
	};

	void Update()
	{
		switch (current_menu)
		{
		case Submenu::Root:
			options_len = OPTIONS_LEN(root_options);
			options = root_options;
			break;
		case Submenu::Main:
			options_len = OPTIONS_LEN(main_options);
			options = main_options;
			break;
		}
	}

	void Draw()
	{
		void* scrPlace = game::scrPlaceView(0);
		void* font = game::UI_GetFontHandle(scrPlace, 3, 1.f);
		const float color[] = { 1.f, 1.f, 1.f, 1.f };

		for(size_t i = 0; i < options_len; i++)
			game::UI_DrawText(scrPlace, options[i].text, 255, font, 100.f, 100.f + (i * 25.f), 0, 0, 1.f, color, 0);
	}
}