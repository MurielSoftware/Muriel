#include "stdafx.h"
#include "ReParser.h"
#include "ReAritmeticOperationExpression.h"
#include "ReNumExpression.h"
#include "ReIdentifierExpression.h"
#include "ReDeclarationExpression.h"
#include "ReIfExpression.h"
#include "ReLexer.h"

namespace Redneck
{
	Parser::Parser(const InputStream& inputStream)
	{
		_lexer = new Lexer(inputStream);
	}

	Parser::~Parser()
	{
		delete _lexer;
	}

	list<Expression*>& Parser::Parse()
	{
		list<Expression*> expressions;
		while (!_lexer->Eof())
		{
			expressions.push_back(Statement());
		}
		return expressions;
	}

	Expression* Parser::Statement()
	{
		Expression* expression = NULL;

		switch (_lexer->Peek().GetTokenType())
		{
		case TokenType::TOKEN_VARIABLE:
			expression = DefineVariable();
			break;
		case TokenType::TOKEN_IF:
			expression = DefineIf();
			break;
		case TokenType::TOKEN_FUNC:
			break;
		default:
			expression = Expr();
			break;
		}

		return expression;
	}

	Expression* Parser::DefineVariable()
	{
		_lexer->Consume(TokenType::TOKEN_VARIABLE);
		string name = _lexer->Next().GetValue();
		_lexer->Consume(TokenType::TOKEN_EQUAL);
		Expression* right = Expr();
		_lexer->Consume(TokenType::TOKEN_SEMI);
		return new DeclarationExpression(new IdentifierExpression(name), right);
	}

	Expression* Parser::DefineIf()
	{
		_lexer->Consume(TokenType::TOKEN_IF);
		_lexer->Consume(TokenType::TOKEN_LBRACKET);
		Expression* condition = Expr();
		_lexer->Consume(TokenType::TOKEN_RBRACKET);
		_lexer->Consume(TokenType::TOKEN_LBRACE);
		Expression* statement = Statement();
		_lexer->Consume(TokenType::TOKEN_RBRACE);

		return new IfExpression(condition, statement);
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
		case TokenType::TOKEN_LBRACKET:
		{
			Expression* expr = Expr();
			_lexer->Consume(TokenType::TOKEN_RBRACKET);
			return expr;
		}
		case TokenType::TOKEN_INT:
			return new NumExpression(nextToken.GetValue());
			break;
		case TokenType::TOKEN_STRING:
			break;
		}
		return NULL;
	}
}