#pragma once

#include "stdafx.h"
#include "ReNumberReader.h"

namespace Redneck
{
	NumberReader::NumberReader()
	{

	}

	NumberReader::~NumberReader()
	{

	}

	bool NumberReader::IsReadable(string s)
	{
		return isdigit(s[0]);
	}

	Token NumberReader::Read(InputStream& inputStream)
	{
		string value;
		while (!inputStream.Eof() && !IsDelimiter(inputStream.Peek()))
		{
			value += inputStream.Get();
		}
		return Token(TOKEN_INT, value);
	}
}