#include "SteamDBApi.h"


Utils* Util;
SteamDBApi::SteamDBApi()
{
	cout << "Init..." << endl;
	Util = new Utils;
}

std::string SteamDBApi::GetLatestBuildID()
{
	//std::string str = GetUrlData();
	//unsigned first = str.find("<td>Build ID</td>");
	//unsigned last = str.find("</td>");


	std::string str = Util->GetData();
	int start = str.find("<td>Build ID</td>");
	int end = str.find("</td>\n</tr>", start);
	std::string substring;
	if (start != std::string::npos && end != std::string::npos)
	{
		substring = str.substr(start + 1, end - start - 1);
	}
	else
	{
		std::cout << "Failed to get BuildId (maybe website down or just timeout ->:(" << std::endl;
	}
	substring = Util->ReplaceAll(substring, "td>Build ID</td>\n<td>", "");
	return substring;
}

bool SteamDBApi::needupdate()
{
	string idfromfile = Util->GetBuildIDFromFile();
	string idfromserver = GetLatestBuildID();

	if (idfromfile.find("ERR1") != string::npos)
	{
		cout << "[INFO] Creating temp file..." << endl;
		Util->TempFile(idfromserver);
		return false;	
	}
	if (idfromfile == idfromserver)
	{
//		cout << "[INFO] Server do not need any updates" << endl;
		return false;
	}
	else
	{
		cout << "[INFO] Updating Servers..." << endl;
		Util->TempFile(idfromserver);
		return true;
	}
	return false;
}
