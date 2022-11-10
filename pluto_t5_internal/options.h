#pragma once
enum Submenu
{
	Root,
	Main,
	// Used to create an array of indices that keep track
	// of the user's last selected options within a submenu.
	// Very hacky but I can't think of a better solution.
	Count
};

enum OptionType
{
	Text,
	Command
};

struct Option
{
	OptionType type;
	Submenu menu;
	const char* text;

	Option() : type(Text), menu(Root), text("OPTION_TEXT") {}
	Option(Submenu menu, const char* text);
};

struct CmdOption : Option
{
	const char* cmd;

	CmdOption(Submenu menu, const char* text, const char* cmd);
};