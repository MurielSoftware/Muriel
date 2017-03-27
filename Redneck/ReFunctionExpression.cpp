#include "stdafx.h"
#include "ReFunctionExpression.h"

namespace Redneck
{
	FunctionExpression::FunctionExpression()
	{

	}

	FunctionExpression::FunctionExpression(Expression* identifier, list<ArgumentExpression*>& arguments, list<Expression*>& statements)
		: _identifier(identifier), _arguments(arguments), _statements(statements)
	{
	}

	FunctionExpression::~FunctionExpression()
	{
		delete _identifier;

		for (ArgumentExpression* argument : _arguments)
		{
			delete argument;
		}

		for (Expression* statement : _statements)
		{
			delete statement;
		}
		_statements.clear();
		_arguments.clear();
	}
}