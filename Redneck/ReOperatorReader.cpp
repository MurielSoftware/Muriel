#pragma once

#include "stdafx.h"
#include "ReOperatorReader.h"

namespace Redneck
{
	map<string, TokenType> OperatorReader::_stringToOperatorTokenType = CreateStringToOperatorTokenType();

	map<string, TokenType> OperatorReader::CreateStringToOperatorTokenType()
	{
		map<string, TokenType> map;
		map.insert(pair<string, TokenType>("+", TokenType::TOKEN_PLUS));
		map.insert(pair<string, TokenType>("-", TokenType::TOKEN_MINUS));
		map.insert(pair<string, TokenType>("*", TokenType::TOKEN_MULT));
		map.insert(pair<string, TokenType>("/", TokenType::TOKEN_DIV));
		map.insert(pair<string, TokenType>("=", TokenType::TOKEN_ASSIGN));
		return map;
	}

	OperatorReader::OperatorReader()
	{

	}

	OperatorReader::~OperatorReader()
	{

	}

	bool OperatorReader::IsReadable(string s)
	{
		return _stringToOperatorTokenType.find(s) != _stringToOperatorTokenType.end();
	}

	Token OperatorReader::Read(InputStream& inputStream)
	{
		string value = inputStream.Get();
		return Token(_stringToOperatorTokenType[value], value);
	}
}