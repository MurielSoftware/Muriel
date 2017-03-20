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

	char InputStream::Peek()
	{
		if (Eof())
		{

		}
		return _source[_currentPosition];
	}

	char InputStream::Get()
	{
		if (Eof())
		{

		}
		return _source[_currentPosition++];
	}

	void InputStream::Ignore()
	{
		_currentPosition++;
	}

	bool InputStream::Eof()
	{
		return _currentPosition >= _source.length();
	}
}