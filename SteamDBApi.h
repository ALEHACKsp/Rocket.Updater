#pragma once
#include "include.h"
class SteamDBApi
{
public: 
	SteamDBApi();
	virtual std::string GetLatestBuildID();
	virtual bool needupdate();
};

