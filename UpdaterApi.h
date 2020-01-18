#pragma once
#include "Utils.h"
class UpdaterApi
{
public:
	UpdaterApi();
	bool Update();
	bool ShutdownServer();
	bool StartServer();
	bool GetPids();
	bool CheckServer();
};

