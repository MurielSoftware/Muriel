#include "stdafx.h"
#include "ReKeywords.h"

namespace Redneck
{
	unordered_map<string, TokenType> Keywords::_keywords = CreateKeywords();

	unordered_map<string, TokenType> Keywords::CreateKeywords()
	{
		unordered_map<string, TokenType> map;
		map.insert(pair<string, TokenType>(KW_VAR, TOKEN_VARIABLE));
		map.insert(pair<string, TokenType>(KW_IF, TOKEN_IF));
		map.insert(pair<string, TokenType>(KW_FUNC, TOKEN_FUNC));
		map.insert(pair<string, TokenType>(KW_WHILE, TOKEN_WHILE));
		map.insert(pair<string, TokenType>(KW_TRUE, TOKEN_TRUE));
		map.insert(pair<string, TokenType>(KW_FALSE, TOKEN_FALSE));
		return map;
	}

	bool Keywords::IsKeyword(const string& name)
	{
		return _keywords.find(name) != _keywords.end();
	}

	TokenType Keywords::GetKeywordTokenType(const string& name)
	{
		return _keywords[name];
	}
}