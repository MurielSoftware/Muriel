#pragma once

#include "stdafx.h"
#include "ReTokenType.h"

#include <string>
#include <vector>
using namespace std;

namespace Redneck
{
	class Parser
	{
	private:
		//bool IsKeyword(const string& s);
		//bool IsIgnored(const string& s);
		//bool IsDelimiter(const char c);
		//bool IsWhitespace(const char c);
		//bool IsArithmeticOperator(const char c);
		//bool IsGreatLessOperator(const char c);
		//vector<string> Scan(const string& s);
		//vector<Token*> Tokenize(vector<string>& scanned);
		//void EatToken(vector<Token*>& tokens);
		//void EatToken(vector<Token*>& tokens, TokenType tokenType);
		//Expression* Parse(vector<Token*>& tokens);
		Lexer* _lexer;

		Expression* Statement();
		Expression* Args();
		Expression* Expr();
		Expression* Term();
		Expression* Factor();

	public:
		Parser();
		virtual ~Parser();

		Expression* Parse();
		//Expression* CreateExpressions(const string& s);
	};
}