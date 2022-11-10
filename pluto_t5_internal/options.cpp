#include "pch.h"
#include "options.h"

Option::Option(Submenu menu, const char* text)
{
	this->type = Text;
	this->menu = menu;
	this->text = text;
}

CmdOption::CmdOption(Submenu menu, const char* text, const char* cmd)
{
	this->type = Command;
	this->menu = menu;
	this->text = text;
	this->cmd = cmd;
}
