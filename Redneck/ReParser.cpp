#include "stdafx.h"
#include "ReParser.h"
#include "ReBinaryOperationExpression.h"
#include "ReValueExpression.h"
#include "ReIdentifierExpression.h"
#include "ReDeclarationExpression.h"
#include "ReAssociationExpression.h"
#include "ReIfExpression.h"
#include "ReArgumentExpression.h"
#include "ReFunctionExpression.h"
#include "ReLexer.h"
#include "ReWhileExpression.h"
#include "ReDataType.h"

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

	list<Expression*> Parser::Parse()
	{
		list<Expression*> expressions;
		while (!_lexer->Eof() && _lexer->Peek().GetTokenType() != TokenType::TOKEN_RBRACE)
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
		case TokenType::TOKEN_WHILE:
			expression = DefineWhile();
			break;
		case TokenType::TOKEN_FUNC:
			expression = DefineFunction();
			break;
		default:
			expression = Expr();
			_lexer->Consume(TokenType::TOKEN_SEMI);
			break;
		}
		return expression;
	}

	Expression* Parser::DefineVariable()
	{
		_lexer->Consume(TokenType::TOKEN_VARIABLE);
		string name = _lexer->Next().GetValue();
		_lexer->Consume(TokenType::TOKEN_ASSIGN);
		Expression* right = Expr();
		_lexer->Consume(TokenType::TOKEN_SEMI);
		return new DeclarationExpression(new IdentifierExpression(name), right);
	}

	Expression* Parser::DefineAssociation()
	{
		string name = _lexer->Next().GetValue();
		_lexer->Consume(TokenType::TOKEN_ASSIGN);
		Expression* right = Expr();
		_lexer->Consume(TokenType::TOKEN_SEMI);
		return new AssociationExpression(new IdentifierExpression(name), right);
	}

	Expression* Parser::DefineIf()
	{
		_lexer->Consume(TokenType::TOKEN_IF);
		_lexer->Consume(TokenType::TOKEN_LBRACKET);
		Expression* condition = Expr();
		_lexer->Consume(TokenType::TOKEN_RBRACKET);
		_lexer->Consume(TokenType::TOKEN_LBRACE);
		list<Expression*> statements = Parse();
		_lexer->Consume(TokenType::TOKEN_RBRACE);
		//if (TokenType::TOKEN_ELSE == _lexer->Peek().GetTokenType())
		//{

		//}
		return new IfExpression(condition, statements);
	}

	Expression* Parser::DefineWhile()
	{
		_lexer->Consume(TokenType::TOKEN_WHILE);
		_lexer->Consume(TokenType::TOKEN_LBRACKET);
		Expression* condition = Expr();
		_lexer->Consume(TokenType::TOKEN_RBRACKET);
		_lexer->Consume(TokenType::TOKEN_LBRACE);
		list<Expression*> statements = Parse();
		_lexer->Consume(TokenType::TOKEN_RBRACE);
		return new WhileExpression(condition, statements);
	}

	Expression* Parser::DefineFunction()
	{
		_lexer->Consume(TokenType::TOKEN_FUNC);
		string name = _lexer->Next().GetValue();
		_lexer->Consume(TokenType::TOKEN_LBRACKET);
		list<ArgumentExpression*> args = DefineArgs();
		_lexer->Consume(TokenType::TOKEN_RBRACKET);
		_lexer->Consume(TokenType::TOKEN_LBRACE);
		list<Expression*> statements = Parse();
		_lexer->Consume(TokenType::TOKEN_RBRACE);

		return new FunctionExpression(new IdentifierExpression(name), args, statements);
	}

	list<ArgumentExpression*> Parser::DefineArgs()
	{
		list<ArgumentExpression*> arguments;
		if (_lexer->Peek().GetTokenType() == TokenType::TOKEN_RBRACKET)
		{
			return arguments;
		}
		string name = _lexer->Next().GetValue();
		arguments.push_back(new ArgumentExpression(name));

		while (_lexer->Peek().GetTokenType() == TOKEN_COMMA)
		{
			_lexer->Consume(TokenType::TOKEN_COMMA);
			name = _lexer->Next().GetValue();
			arguments.push_back(new ArgumentExpression(name));
		}
		return arguments;
	}

	Expression* Parser::Expr()
	{
		Expression* t = Term();
		Token nextToken = _lexer->Peek();
		while (!_lexer->Eof() && (nextToken.GetTokenType() == TOKEN_PLUS || nextToken.GetTokenType() == TOKEN_MINUS))
		{
			_lexer->Next();
			Expression* expr = new BinaryOperationExpression(t, Term(), nextToken.GetValue());
			nextToken = _lexer->Peek();
			t = expr;
		}
		return t;
	}
	
	Expression* Parser::Term()
	{
		Expression* f = Bool();
		Token nextToken = _lexer->Peek();
		while (!_lexer->Eof() && (nextToken.GetTokenType() == TOKEN_MULT || nextToken.GetTokenType() == TOKEN_DIV))
		{
			_lexer->Next();
			Expression* term = new BinaryOperationExpression(f, Bool(), nextToken.GetValue());
			nextToken = _lexer->Peek();
			f = term;
		}
		return f;
	}

	Expression* Parser::Bool()
	{
		Expression* f = Assignment();
		Token nextToken = _lexer->Peek();
		while (!_lexer->Eof() && (nextToken.GetTokenType() == TOKEN_GREATER
			|| nextToken.GetTokenType() == TOKEN_GREATER_EQUAL
			|| nextToken.GetTokenType() == TOKEN_LESS 
			|| nextToken.GetTokenType() == TOKEN_LESS_EQUAL
			|| nextToken.GetTokenType() == TOKEN_EQUALS 
			|| nextToken.GetTokenType() == TOKEN_NOT_EQUALS))
		{
			_lexer->Next();
			Expression* term = new BinaryOperationExpression(f, Expr(), nextToken.GetValue());
			nextToken = _lexer->Peek();
			f = term;
		}
		return f;
	}

	Expression* Parser::Assignment()
	{
		Expression* f = Factor();
		Token nextToken = _lexer->Peek();
		while (!_lexer->Eof() && nextToken.GetTokenType() == TOKEN_ASSIGN)
		{
			_lexer->Next();
			Expression* term = new AssociationExpression(f, Expr());
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
		case TokenType::TOKEN_IDENTIFIER:
			return new IdentifierExpression(nextToken.GetValue());
		case TokenType::TOKEN_LBRACKET:
		{
			Expression* expr = Expr();
			_lexer->Consume(TokenType::TOKEN_RBRACKET);
			return expr;
		}
		case TokenType::TOKEN_INT:
		case TokenType::TOKEN_STRING:
		case TokenType::TOKEN_FLOAT:
		case TokenType::TOKEN_FALSE:
		case TokenType::TOKEN_TRUE:
			return new ValueExpression(nextToken.GetValue());
		}
		return NULL;
	}
}