#pragma once

#include "stdafx.h"
//#include "FileTypes.h"

namespace Muriel
{
	class MURIEL_API FileUtils
	{
	private:
	protected:
	public:
		//static FileTypes GET_FILE_TYPE(const string& path);
		static string GET_FILE_NAME(const string& path);
		static string GET_PATH(const string& path);
		static string READ_FILE(const string& path);
	};
}