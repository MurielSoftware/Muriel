#pragma once

#define KW_VAR "var"
#define KW_IF "if"
#define KW_FUNC "func"
#define KW_WHILE "while"
#define KW_TRUE "true"
#define KW_FALSE "false"

#include "ReTokenType.h"

namespace Redneck
{
	class Keywords
	{
	private:
		static unordered_map<string, TokenType> _keywords;
		static unordered_map<string, TokenType> CreateKeywords();
	public:
		static bool IsKeyword(const string& name);
		static TokenType GetKeywordTokenType(const string& name);
	};
}