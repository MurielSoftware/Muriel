#include "stdafx.h"
#include "ReAritmeticOperationExpression.h"
#include "ReStackVisitor.h"

namespace Redneck
{
	AritmeticOperationExpression::AritmeticOperationExpression()
	{
	}

	AritmeticOperationExpression::AritmeticOperationExpression(Expression* arg0, Expression* arg1, char op)
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

	void AritmeticOperationExpression::Accept(StackVisitor& stackVisitor)
	{
		stackVisitor.Visit(*this);
	}
}