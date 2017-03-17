#include "stdafx.h"
#include "ReParser.h"
#include "ReAritmeticOperationExpression.h"
#include "ReNumExpression.h"
#include "ReToken.h"
#include "ReLexer.h"
#include <regex>
#include <sstream>

namespace Redneck
{
	Parser::Parser()
	{
		_lexer = new Lexer("2*3+2*3");
	}

	Parser::~Parser()
	{
		delete _lexer;
	}

	Expression* Parser::Parse()
	{
		//while (!_lexer->Eof())
		//{
			return Statement();
		//}
	}

	Expression* Parser::Statement()
	{
		Expression* expression = NULL;

		switch (_lexer->Peek().GetTokenType())
		{
		case TokenType::TOKEN_VARIABLE:
			break;
		case TokenType::TOKEN_IF:
			break;
		case TokenType::TOKEN_FUNC:
			break;
		default:
			expression = Expr();
			break;
		}

		return expression;
	}

	Expression* Parser::Args()
	{
		return NULL;
	}

	Expression* Parser::Expr()
	{
		Expression* t = Term();
		Token nextToken = _lexer->Peek();
		while (!_lexer->Eof() && (nextToken.GetTokenType() == TOKEN_PLUS || nextToken.GetTokenType() == TOKEN_MINUS))
		{
			_lexer->Next();
			Expression* expr = new AritmeticOperationExpression(t, Term(), nextToken.GetValue()[0]);
			nextToken = _lexer->Peek();
			t = expr;
		}
		return t;
	}
	
	Expression* Parser::Term()
	{
		Expression* f = Factor();
		Token nextToken = _lexer->Peek();
		while (!_lexer->Eof() && (nextToken.GetTokenType() == TOKEN_MULT || nextToken.GetTokenType() == TOKEN_DIV))
		{
			_lexer->Next();
			Expression* term = new AritmeticOperationExpression(f, Factor(), nextToken.GetValue()[0]);
			nextToken = _lexer->Peek();
			f = term;
		}
		return f;
	}

	Expression* Parser::Factor()
	{
		Token nextToken = _lexer->Next();
		switch (nextToken.GetTokenType())
		{
		case TokenType::TOKEN_INT:
			return new NumExpression(nextToken.GetValue());
			break;
		case TokenType::TOKEN_STRING:
			break;
		}
	}
}