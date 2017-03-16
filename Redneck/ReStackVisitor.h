#pragma once

#include "stdafx.h"

#include <stack>
using namespace std;

namespace Redneck
{
	class StackVisitor
	{
	private:
		stack<int>& _valueStack;
		stack<Expression*>& _expressionStack;
	public:
		StackVisitor(stack<Expression*>& expressionStack, stack<int>& valueStack);
		virtual ~StackVisitor();

		void Visit(NumExpression& exp);
		void Visit(AritmeticOperationExpression& exp);
	};
}