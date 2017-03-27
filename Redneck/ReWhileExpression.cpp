#include "stdafx.h"
#include "ReWhileExpression.h"

namespace Redneck
{
	WhileExpression::WhileExpression()
	{
	}

	WhileExpression::WhileExpression(Expression* condition, list<Expression*>& statements)
	{
		_condition = condition;
		_statements = statements;
	}

	WhileExpression::~WhileExpression()
	{
		delete _condition;

		for (Expression* statement : _statements)
		{
			delete statement;
		}
		_statements.clear();
	}
}