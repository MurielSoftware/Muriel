#pragma once

#include "stdafx.h"
#include "ReIdentifierReader.h"

namespace Redneck
{
	IdentifierReader::IdentifierReader()
	{

	}

	IdentifierReader::~IdentifierReader()
	{

	}

	bool IdentifierReader::IsReadable(string s)
	{
		return isalpha(s[0]);
	}

	Token IdentifierReader::Read(InputStream& inputStream)
	{
		string value;
		while (!inputStream.Eof() && !IsDelimiter(string(1, inputStream.Peek())))
		{
			value += inputStream.Get();
		}
		if (value == "var")
		{
			return Token(TOKEN_VARIABLE, value);
		}
		return Token(TOKEN_IDENTIFIER, value);
	}
}