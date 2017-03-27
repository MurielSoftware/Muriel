#include "stdafx.h"
#include "ReIfExpression.h"

namespace Redneck
{
	IfExpression::IfExpression()
	{
	}

	IfExpression::IfExpression(Expression* condition, list<Expression*>& statements)
	{
		_condition = condition;
		_statements = statements;
	}

	IfExpression::~IfExpression()
	{
		delete _condition;

		for (Expression* statement : _statements)
		{
			delete statement;
		}
		_statements.clear();
	}
}