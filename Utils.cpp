#include "Utils.h"
Utils::Utils()
{
	cout << "Utils Init." << endl;
}

std::string Utils::GetData()
{

		std::string url = "/depot/304935/";
		while (true)
		{
			std::string request_data = ("");
			HINTERNET hIntSession = InternetOpenA((""), 1, NULL, NULL, 0);
			if (!hIntSession)
			{
				return request_data;
			}
			HINTERNET hHttpSession = InternetConnectA(hIntSession, "steamdb.info", 443, 0, 0, 3, 0, NULL);
			if (!hHttpSession)
			{
				return request_data;
			}
			HINTERNET hHttpRequest = HttpOpenRequestA(hHttpSession, ("GET"), url.c_str()
				, 0, 0, 0, 0x00800000 | 0x04000000, 0);
			if (!hHttpSession)
			{
				return request_data;
			}
			std::string szHeaders = (("Content-Type: text/html\r\nUser-Agent: License\r\nUSER-AGENT: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.108 Safari/537.36"));
			LPCSTR szHeadersL = szHeaders.c_str();
			char szRequest[1024] = { 0 };
			if (!HttpSendRequestA(hHttpRequest, szHeadersL, strlen(szHeadersL), szRequest, strlen(szRequest)))
			{
				return request_data;
			}
			CHAR szBuffer[1024] = { 0 };
			DWORD dwRead = 0;
			while (InternetReadFile(hHttpRequest, szBuffer, sizeof(szBuffer) - 1, &dwRead) && dwRead)
			{
				request_data.append(szBuffer, dwRead);
			}
			InternetCloseHandle(hHttpRequest);
			InternetCloseHandle(hHttpSession);
			InternetCloseHandle(hIntSession);
			return request_data;
		}
	
}

std::string Utils::ReplaceAll(std::string str, const std::string& from, const std::string& to)
{
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
	}
	return str;

}
std::string Utils::GetStringAfterAnotherString(std::string str, const std::string& from)
{
	int pos = str.find(from);
	string sub = str.substr(pos + 1);
	return sub;

}
string Utils::GetBuildIDFromFile()
{
	string line;
	ifstream tempfile("beast.temp");
	if (tempfile.is_open())
	{
		getline(tempfile, line);
		tempfile.close();
	}
	else
	{
		return "ERR1";
	}
	if (!line.compare(""))
	{
		cout << "[WARNINGS] File empty, recreating it rn." << endl;
		return "ERR1";
	}
	return line;
}
bool Utils::TempFile(string buildid)
{

		ofstream tempfile("beast.temp");
		if (tempfile.is_open())
		{
			tempfile << buildid;
			tempfile.close();
			return true;
		}
		else
		{
			cout << "[ERROR] Failed to open file " << GetLastError() <<  endl;
			return false;
		}
	return false;
}
