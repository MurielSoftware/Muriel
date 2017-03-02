#pragma once

#include "stdafx.h"
#include "MuSingleton.h"
#include <string>
#include <fstream>
#include <map>

namespace Muriel
{

#define LOG(message) Log::GetInstance()->LogMessage(message)
#define LOG_WARNING(message) Log::GetInstance()->LogWarning(message)
#define LOG_ERROR(message) Log::GetInstance()->LogError(message)

	enum LogType
	{
		MESSAGE,
		WARNING,
		ERRORS
	};

	class Log : public Singleton<Log>
	{
	private:
		ofstream _file;
		
		static map<LogType, string> TYPE_TO_COLOR;

		void Init();
		string GetTime();
		void WriteMessage(LogType type, const string& message);
	public:
		Log();
		virtual ~Log();
		void Destroy();

		void LogMessage(const string& message);
		void LogWarning(const string& message);
		void LogError(const string& message);
	};
}