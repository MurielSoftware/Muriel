#pragma once

namespace Redneck
{
	enum TokenType
	{
		TOKEN_INT,
		TOKEN_STRING,
		TOKEN_FLOAT,
		TOKEN_FALSE,
		TOKEN_TRUE,
		TOKEN_IDENTIFIER,
		TOKEN_VARIABLE,
		TOKEN_WHILE,
		TOKEN_IF,
		TOKEN_FUNC,
		TOKEN_ELSE,
		
		TOKEN_COMMA,
		TOKEN_SEMI,
		TOKEN_LBRACKET,
		TOKEN_RBRACKET,
		TOKEN_LBRACE,
		TOKEN_RBRACE,
		TOKEN_ASSIGN,

		TOKEN_PLUS,
		TOKEN_MINUS,
		TOKEN_MULT,
		TOKEN_DIV,

		TOKEN_NULL,

		TOKEN_EQUALS,
		TOKEN_GREATER,
		TOKEN_LESS,
		TOKEN_LESS_EQUAL,
		TOKEN_GREATER_EQUAL,
		TOKEN_NOT_EQUALS
	};
}