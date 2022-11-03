#pragma once
#define OPTIONS_LEN(o) (sizeof(o) / sizeof(Option))

enum OptionType
{
	Text,
	Command,
};

class Option
{
public:
	OptionType type = OptionType::Text;
	// std::string would be nice but alas, we are in a DLL
	const char* text = "";
	const char* command = "";
	Option() : text("TEXT_OPTION") {}
	Option(const char* text) : text(text) {}
};

class CmdOption : public Option
{
public:
	CmdOption(const char* text, const char* cmd);
};