#include "stdafx.h"
#include "ReIfExpression.h"

namespace Redneck
{
	IfExpression::IfExpression()
	{
	}

	IfExpression::IfExpression(Expression* condition, Expression* statement)
	{
		_condition = condition;
		_statement = statement;
	}

	IfExpression::~IfExpression()
	{
		delete _condition;
		delete _statement;
	}
}