#include "pch.h"
#include "options.h"

CmdOption::CmdOption(const char* text, const char* cmd)
{
	this->type = OptionType::Command;
	this->text = text;
	this->command = cmd;
}
