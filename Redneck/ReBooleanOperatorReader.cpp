#pragma once

#include "stdafx.h"
#include "ReBooleanOperatorReader.h"

namespace Redneck
{
	map<string, TokenType> BooleanOperatorReader::_stringToTokenBooleanOperatorTokenType = CreateStringToTokenBooleanOperatorTokenType();

	map<string, TokenType> BooleanOperatorReader::CreateStringToTokenBooleanOperatorTokenType()
	{
		map<string, TokenType> map;
		map.insert(pair<string, TokenType>("<", TokenType::TOKEN_LESS));
		map.insert(pair<string, TokenType>(">", TokenType::TOKEN_GREATER));
		map.insert(pair<string, TokenType>("<=", TokenType::TOKEN_LESS_EQUAL));
		map.insert(pair<string, TokenType>(">=", TokenType::TOKEN_GREATER_EQUAL));
		map.insert(pair<string, TokenType>("!=", TokenType::TOKEN_NOT_EQUALS));
		map.insert(pair<string, TokenType>("==", TokenType::TOKEN_EQUALS));
		return map;
	}

	BooleanOperatorReader::BooleanOperatorReader()
	{

	}

	BooleanOperatorReader::~BooleanOperatorReader()
	{

	}

	bool BooleanOperatorReader::IsReadable(string s)
	{
		return _stringToTokenBooleanOperatorTokenType.find(s) != _stringToTokenBooleanOperatorTokenType.end();
	}

	Token BooleanOperatorReader::Read(InputStream& inputStream)
	{
		string value = inputStream.Get();
		return Token(_stringToTokenBooleanOperatorTokenType[value], value);
	}
}