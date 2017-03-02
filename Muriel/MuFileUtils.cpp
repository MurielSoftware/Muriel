#include "stdafx.h"
#include "MuFileUtils.h"
#include <fstream>

namespace Muriel
{
	//FileTypes FileUtils::GET_FILE_TYPE(const string& path)
	//{
	//	int pathLength = path.find_last_of(".") + 1;
	//	string extension = path.substr(pathLength, path.size() - pathLength);
	//	if (extension == "ms3d")
	//	{
	//		return FileTypes::MS3D;
	//	}
	//	else if (extension == "mlv")
	//	{
	//		return FileTypes::MLV;
	//	}
	//	else if (extension == "mmf")
	//	{
	//		return FileTypes::MMF;
	//	}
	//}

	string FileUtils::GET_FILE_NAME(const string& path)
	{
		int lastSlash = path.find_last_of("/");
		if (lastSlash == -1)
		{
			lastSlash = path.find_last_of("\\");
		}
		lastSlash++;
		string fileName = path.substr(lastSlash, path.size() - lastSlash);
		return fileName.substr(0, fileName.find_last_of("."));
	}

	string FileUtils::GET_PATH(const string& path)
	{
		return path.substr(0, path.find_last_of("/") + 1);
	}

	string FileUtils::READ_FILE(const string& path)
	{
		ifstream file(path);
		if (file.fail())
		{
			return "";
		}
		string content;
		content.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
		file.close();
		return content;
	}
}