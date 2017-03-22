#include "stdafx.h"
#include "ReInputStream.h"

#include <fstream>

using namespace std;

namespace Redneck
{
	InputStream::InputStream()
	{

	}

	InputStream::InputStream(const string& path)
	{
		ifstream input(path);
		if (!input.is_open())
		{
			return;
		}
		_source = string((istreambuf_iterator<char>(input)), istreambuf_iterator<char>());
		input.close();
		_currentPosition = 0;
	}

	InputStream::~InputStream()
	{

	}

	string InputStream::Peek()
	{
		if (Eof())
		{

		}
		string current = string(1, _source[_currentPosition]);
		IsTwoCharToken(current);
	//	if (current == "=" && _source[_currentPosition+1] == '=')
		//if(ThisAndNextIs("=", "="))
		//{
		//	current += "=";
		//} 
		//else if (ThisAndNextIs("!", "="))
		//{
		//	current += "=";
		//}
		//else if (ThisAndNextIs("<", "="))
		//{
		//	current += "=";
		//}
		//else if (ThisAndNextIs(">", "="))
		//{
		//	current += "=";
		//}
		//else if (ThisAndNextIs("|", "|"))
		//{
		//	current += "|"
		//}
		//else if (ThisAndNextIs("&", "&"))
		//{
		//	current += "&";
		//}
		return current;
	}

	string InputStream::Get()
	{
		if (Eof())
		{

		}
		string current = string(1, _source[_currentPosition]);
		if (IsTwoCharToken(current))
		{
			//current += "=";
			_currentPosition++;
		}
		_currentPosition++;
		return current;
	}

	void InputStream::Ignore()
	{
		_currentPosition++;
	}

	bool InputStream::Eof()
	{
		return _currentPosition >= _source.length();
	}

	bool InputStream::IsTwoCharToken(string& current)
	{
		if (ThisAndNextIs("=", "="))
		{
			current += "=";
		}
		else if (ThisAndNextIs("!", "="))
		{
			current += "=";
		}
		else if (ThisAndNextIs("<", "="))
		{
			current += "=";
		}
		else if (ThisAndNextIs(">", "="))
		{
			current += "=";
		}
		else if (ThisAndNextIs("|", "|"))
		{
			current += "|";
		}
		else if (ThisAndNextIs("&", "&"))
		{
			current += "&";
		}

		if (current.length() == 2)
		{
			return true;
		}
		return false;
	}

	bool InputStream::ThisAndNextIs(const string& th, const string& ne)
	{
		return string(1, _source[_currentPosition]) == th && string(1, _source[_currentPosition + 1]) == ne;
	}
}