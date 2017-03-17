#include "stdafx.h"
#include "ReInputStream.h"

namespace Redneck
{
	InputStream::InputStream()
	{

	}

	InputStream::InputStream(const string& path)
	{
		_source = path;
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