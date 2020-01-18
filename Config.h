#pragma once
#include "Utils.h"

//ghetto config system aka trash but working so ._. 
class Config
{
public:
	Config();
	Config(int numbserv);
	static string get_config(string whattogetustupid);
};

