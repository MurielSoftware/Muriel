#include "stdafx.h"
#include "MuLog.h"
#include <ctime>

namespace Muriel
{
	map<LogType, string> Log::TYPE_TO_COLOR = 
	{
		{ LogType::ERRORS, "<tr style='background: #ff6347'><td>ERROR</td>" },
		{ LogType::WARNING, "<tr style='background: #ffff7e'><td>WARNING</td>" },
		{ LogType::MESSAGE, "<tr style='background: #ffffff'><td>WARNING</td>" }
	};

	Log::Log()
	{
		Init();
	}

	Log::~Log()
	{
		Destroy();
	}

	void Log::LogMessage(const string& message)
	{
		WriteMessage(LogType::MESSAGE, message);
	}

	void Log::LogWarning(const string& message)
	{
		WriteMessage(LogType::WARNING, message);
	}

	void Log::LogError(const string& message)
	{
		WriteMessage(LogType::ERRORS, message);
	}

	void Log::Init()
	{
		_file.open("data/log.html", fstream::out);
		_file << "<html>";
		_file << "<style type='text/css'>";
		_file << "table { width: 100% }";
		_file << "table, th, tr, td { border:1px solid black; }";
		_file << "th { font-weight: bold; }";
		_file << "</style>";
		_file << "<h3>LOG - " << GetTime() << "</h3>";
		_file << "<table>";
		_file << "<th style='width:120px'>Type</th><th style='width:80px'>Time</th><th>Message</th>";
	}

	void Log::Destroy()
	{
		_file << "</table>";
		_file << "Log was closed at: " << GetTime() << "</html>";
		_file.close();
	}

	string Log::GetTime()
	{
		time_t rawtime;
		struct tm timeInfo;
		char buffer[80];

		time(&rawtime);
		localtime_s(&timeInfo, &rawtime);
		strftime(buffer, 80, "%H:%M:%S", &timeInfo);
		return string(buffer);
	}

	void Log::WriteMessage(LogType type, const string& message)
	{
		_file << TYPE_TO_COLOR[type];
		_file << "<td>" << GetTime() << "</td>";
		_file << "<td>" << message << "</td>";
		_file << "</tr>";
		_file.flush();
	}
}