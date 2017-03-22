#include "stdafx.h"
#include "ReWhileExpression.h"

namespace Redneck
{
	WhileExpression::WhileExpression()
	{
	}

	WhileExpression::WhileExpression(Expression* condition, Expression* statement)
	{
		_condition = condition;
		_statement = statement;
	}

	WhileExpression::~WhileExpression()
	{
		delete _condition;
		delete _statement;
	}
}