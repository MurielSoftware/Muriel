#pragma once

#include "stdafx.h"
#include <string>
#include <stack>

using namespace std;

namespace Redneck
{
	class REDNECK_API Interpreter
	{
	private:
		stack<Expression*> _expressionStack;
		stack<int> _valueStack;
		StackVisitor* _stackVisitor;

		template<class T> T Stack_Pop(stack<T>& stack);
	public:
		Interpreter();
		virtual ~Interpreter();

		Expression* CreateExpressions(const string& s);
		void Interpret(Expression* expression);
	};
}