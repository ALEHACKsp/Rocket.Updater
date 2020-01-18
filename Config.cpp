#include "Config.h"

 bool file_existt(const std::string& name) {
	if (FILE* file = fopen(name.c_str(), "r")) {
		fclose(file);
		return true;
	}
	else {
		return false;
	}
}

Config::Config()
{
	cout << "[INFO] Config Init" << endl;
	if (!file_existt("beast.conf"))
	{
		cout << "[INFO] Creating Config file, please change it with right value" << endl;
		Sleep(50);
		ofstream confile("beast.conf");
		if (confile.is_open())
		{
			confile << "SteamCmdPath: C:\\mysteamcmd_yay_.exe\n";
			confile << "SteamUsername: SteamUsername\n";
			confile << "SteamPassword: SteamPassword";
			confile << "--------------------------";

			confile << "TestServer: C:\\steamapps\\commons\\imtheunturnedserver_PS_IM_A_FOLDER\n";
			confile << "TestServerPort: 13337\n";
			confile << "ServerStarterBat: C:\\start.bat	\n";

			
			confile.close();
		}
		else
		{
			cout << "[ERROR] Failed to open config files, -> open me as admin" << endl;
		}
		
		cout << "[INFO] Created config file" << endl;
	}
	cout << "[INFO] Finished config init" << endl;
}
Config::Config(int numbserv)
{
	cout << "[INFO] Config Init" << endl;
	if (!file_existt("beast.conf"))
	{
		cout << "[INFO] Creating Config file, please change it with right value" << endl;
		Sleep(50);
		ofstream confile("beast.conf");
		if (confile.is_open())
		{
			confile << "This program have been made for unturnedbeast.com, you are not allowed to reuse this program for your server, if your name is dronxa then all good.\nThis program haven't been made for commercial use.\n\n";
			
			confile << "This is used for debugging" << endl;
			confile << "NumbersOfServers: " << numbserv << endl;
			confile << endl << "Steam configuration, used to update" << endl;
			confile << "SteamCmdPath: C:\\steamcmd.exe" << endl;
			confile << "SteamUsername: SteamUsername" << endl;
			confile << "SteamPassword: SteamPassword" << endl;
			confile << endl;
			for (int i = 0; i < numbserv; i++)
			{
				confile << "--------------------------" << endl;
				confile << "Server" << i << "Path: " << "C:\\UnturnedServer" << endl;
				confile << "Server" << i << "Port: " << "27015" << endl;
				confile << "Server" << i << "StartBat: " << "C:\\start.bat" << endl;

			}
		
			confile.close();
		}
		else
		{
			cout << "[ERROR] Failed to open config files, -> open me as admin" << endl;
		}

		cout << "[INFO] Created config file" << endl;
	}
	cout << "[INFO] Finished config init | Stats, Created: " << numbserv << " servers" << endl;
}


string Config::get_config(string whattogetustupid)
{
	string line;
	ifstream ConfFile("beast.conf");
	if (ConfFile.is_open())
	{
		while (getline(ConfFile, line))
		{
			if (line.find(whattogetustupid) != string::npos)
			{
				whattogetustupid += ": ";
				line = Utils::ReplaceAll(line, whattogetustupid, "");
				return line;
			}
		}
		ConfFile.close();
	}
	else
	{
		cout << "[ERROR] Can't open config file!";
	}
	if (!line.compare(""))
	{
		cout << "[WARNINGS] Please delete old config file and relaunch me?" << endl;
		return "ERR1";
	}
	return line;
}
