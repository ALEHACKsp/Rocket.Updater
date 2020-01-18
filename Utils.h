#pragma once
#include <string>
#include "include.h"

class Utils
{
public:
	Utils();
	virtual std::string GetData();
	static std::string ReplaceAll(std::string str, const std::string& from, const std::string& to);
	static std::string GetStringAfterAnotherString(std::string str, const std::string& from);
	string GetBuildIDFromFile();
	virtual bool TempFile(string buildid);
};

