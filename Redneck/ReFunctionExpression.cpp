#include "stdafx.h"
#include "ReFunctionExpression.h"

namespace Redneck
{
	FunctionExpression::FunctionExpression()
	{

	}

	FunctionExpression::FunctionExpression(Expression* identifier, list<ArgumentExpression*>& arguments, Expression* statement)
		: _identifier(identifier), _arguments(arguments), _statement(statement)
	{
	}

	FunctionExpression::~FunctionExpression()
	{
		delete _identifier;
		delete _statement;

		for (ArgumentExpression* argument : _arguments)
		{
			delete argument;
		}
		_arguments.clear();
	}
}