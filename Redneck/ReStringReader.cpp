#pragma once

#include "stdafx.h"
#include "ReStringReader.h"

namespace Redneck
{
	StringReader::StringReader()
	{

	}

	StringReader::~StringReader()
	{

	}

	bool StringReader::IsReadable(string s)
	{
		return s[0] == '"';
	}

	Token StringReader::Read(InputStream& inputStream)
	{
		string value;
		inputStream.Ignore();
		while (!inputStream.Eof() && inputStream.Peek() != '"')
		{
			value += inputStream.Get();
		}
		inputStream.Ignore();
		return Token(TOKEN_STRING, value);
	}
}