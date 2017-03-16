#include "stdafx.h"
#include "ReStackVisitor.h"
#include "ReAritmeticOperationExpression.h"
#include "ReNumExpression.h"

namespace Redneck
{
	StackVisitor::StackVisitor(stack<Expression*>& expressionStack, stack<int>& valueStack)
		: _valueStack(valueStack), _expressionStack(expressionStack)
	{
	}

	StackVisitor::~StackVisitor()
	{

	}

	void StackVisitor::Visit(NumExpression& exp)
	{
		_valueStack.push(exp.GetValue());
	}

	void StackVisitor::Visit(AritmeticOperationExpression& exp)
	{
		_expressionStack.push(exp.GetArg1());
		_expressionStack.push(exp.GetArg0());
		_valueStack.push(exp.GetOperator());
	}
}
