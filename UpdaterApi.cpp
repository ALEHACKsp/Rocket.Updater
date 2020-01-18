#include "UpdaterApi.h"
#include <vector>

UpdaterApi::UpdaterApi()
{
	cout << "Init Updater" << endl;
}
bool UpdaterApi::Update()
{

	for (int i = 0; i < std::stoi(Config::get_config("NumbersOfServers")); i++)
	{
		string configsearch;
		configsearch.append(Config::get_config("Server"));
		configsearch.append(to_string(i));
		configsearch.append("Path");
	
		string steamcmdpath = "";
		steamcmdpath.append("\"");
		steamcmdpath.append(Config::get_config("SteamCmdPath"));
		steamcmdpath.append("\"");
		steamcmdpath.append(" +login ");
		steamcmdpath.append(Config::get_config("SteamUsername"));
		steamcmdpath.append(" ");
		steamcmdpath.append(Config::get_config("SteamPassword"));
		steamcmdpath.append(" +force_install_dir ");
		steamcmdpath.append(Config::get_config(configsearch.c_str()));
		steamcmdpath.append(" +app_update 304930 +exit ");
		cout << "SteamCmd Launcher with args: " << steamcmdpath.c_str() << endl;
		system(steamcmdpath.c_str());
	}


}


string GetUnturnedServerPID()
{
	string toreturn = "no";
	string line;
	ifstream tempfile("output.temp");
	if (tempfile.is_open())
	{
		getline(tempfile, line);
		if (line.find("LISTENING") != string::npos)
		{
			toreturn = Utils::GetStringAfterAnotherString(line, "LISTENING       ");
		}
		tempfile.close();
	}
	else
	{
		return "no";
	}
	if (!line.compare(""))
	{
		cout << "[WARNINGS] File empty, recreating it rn." << endl;
		return "no";
	}
	toreturn = Utils::ReplaceAll(toreturn, "ISTENING       ", "");
	return toreturn;
}

int strtoint(string str)
{
	return std::stoi(str);

}
bool UpdaterApi::ShutdownServer()
{
	for (int i = 0; i < std::stoi(Config::get_config("NumbersOfServers")); i++)
	{
		string configsearch;
		configsearch.append(Config::get_config("Server"));
		configsearch.append(to_string(i));
		configsearch.append("Port");

		string pa;
		pa.append("netstat -a -n -o | find \"");
		pa.append(Config::get_config(configsearch.c_str()));
		pa.append("\" | find \"LISTENING\" > output.temp");
		system(pa.c_str());
		Sleep(200); // to be sure command is finished
		string pid = GetUnturnedServerPID();
		if (pid.find("no") != string::npos)
		{
			cout << "[ERROR] Failed to get unturned server port pid." << endl;
			return false;
		}

		cout << "[INFO] Killing unturned server with pid: \'" << pid << "\'.";
		string po;
		po.append("taskkill /F /PID ");
		po.append(pid);
		system(po.c_str());
		system(po.c_str());
		system(po.c_str());
		system(po.c_str());
		system(po.c_str());

	}

	return true;
}

bool UpdaterApi::StartServer()
{
	for (int i = 0; i < strtoint(Config::get_config("NumbersOfServers")); i++)
	{
		string configsearch;
		configsearch.append(Config::get_config("Server"));
		configsearch.append(to_string(i));
		configsearch.append("StartBat");

		string startstring;
		startstring.append("\""); // this is a fix, if you have a space in ur path then program will fail , so we are adding " to prevent
		startstring.append(Config::get_config(configsearch.c_str()));
		startstring.append("\""); // this is a fix, if you have a space in ur path then program will fail , so we are adding " to prevent


		system(startstring.c_str());

	}

	return true;
}


bool UpdaterApi::CheckServer()
{
	for (int i = 0; i < std::stoi(Config::get_config("NumbersOfServers")); i++)
	{
		string configsearch;
		configsearch.append(Config::get_config("Server"));
		configsearch.append(to_string(i));
		configsearch.append("Port");

		string pa;
		pa.append("netstat -a -n -o | find \"");
		pa.append(Config::get_config(configsearch.c_str()));
		pa.append("\" | find \"LISTENING\" > output.temp");
		system(pa.c_str());
		Sleep(200); // to be sure command is finished
		string pid = GetUnturnedServerPID();
		if (pid.find("no") != string::npos)
		{
			cout << "[INFO] Server " << to_string(i) << " is restarting. (failed to get port)" << endl;

			string configsearch;
			configsearch.append(Config::get_config("Server"));
			configsearch.append(to_string(i));
			configsearch.append("StartBat");

			string startstring;
			startstring.append("\""); // this is a fix, if you have a space in ur path then program will fail , so we are adding " to prevent
			startstring.append(Config::get_config(configsearch.c_str()));
			startstring.append("\""); // this is a fix, if you have a space in ur path then program will fail , so we are adding " to prevent


			system(startstring.c_str());


			return true;
		}

	}
	return true;
}