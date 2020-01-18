// RealBeastUpdated.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Utils.h"
#pragma once

bool file_exist(const std::string& name) {
	if (FILE* file = fopen(name.c_str(), "r")) {
		fclose(file);
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	SteamDBApi* SteamApi = new SteamDBApi();
	UpdaterApi* updater = new UpdaterApi();
	system("cls");
	if (!file_exist("beast.conf"))
	{
		int servcount = 0;
		cout << "How much servers you want the program to monitor and auto update?" << endl;
		cin >> servcount;
		if (servcount >= 0)
		{
			Config* conf = new Config(servcount);
		}
		else
		{
			cout << "[ERROR] Server count can't be less than 1; ex : 0 or -1" << endl;
		}

	}
	Sleep(2000);
	system("cls");

	cout << "\x1B[31mUnturnedBeast.com\033[0m \x1B[36mServer updater, Running\033[0m\t\t" << endl;
	while (true) {
		if (SteamApi->needupdate())
		{
			if (updater->ShutdownServer())
			{
				cout << "[INFO] Server look like dead." << endl;
				cout << "[INFO] Restarting It." << endl;
				updater->StartServer();
			}
			else
			{
				cout << "[ERROR] Failed to shutdown server." << endl;
			}

			// update
			if (updater->Update())
			{
				cout << "[INFO] Updating server" << endl;
			}
			else
			{
				cout << "[ERROR] Failed to update server." << endl;
			}
		}
		else
		{
		}
		Sleep(900); // 15 minutes (for steamdb to not ban us)
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
