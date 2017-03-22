#include "stdafx.h"
#include "ReAritmeticOperationExpression.h"

namespace Redneck
{
	AritmeticOperationExpression::AritmeticOperationExpression()
	{
	}

	AritmeticOperationExpression::AritmeticOperationExpression(Expression* arg0, Expression* arg1, const string& op)
	{
		_arg0 = arg0;
		_arg1 = arg1;
		_operator = op;
	}

	AritmeticOperationExpression::~AritmeticOperationExpression()
	{
		delete _arg0;
		delete _arg1;
	}
}