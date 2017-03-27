#include "stdafx.h"
#include "ReBinaryOperationExpression.h"

namespace Redneck
{
	BinaryOperationExpression::BinaryOperationExpression()
	{
	}

	BinaryOperationExpression::BinaryOperationExpression(Expression* arg0, Expression* arg1, const string& op)
	{
		_arg0 = arg0;
		_arg1 = arg1;
		_operator = op;
	}

	BinaryOperationExpression::~BinaryOperationExpression()
	{
		delete _arg0;
		delete _arg1;
	}
}