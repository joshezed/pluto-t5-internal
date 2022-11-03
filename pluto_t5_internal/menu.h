#pragma once
namespace menu
{
	enum Submenu
	{
		Root,
		Main,
		// Used to create an array of indices that keep track
		// of the user's last selected options within a submenu
		Count
	};

	void Update();
	void Draw();
}