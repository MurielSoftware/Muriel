#include "stdafx.h"
#include "ReInterpreter.h"
#include "ReParser.h"
#include "ReExpression.h"
#include "ByteCodeId.h"
#include "ReStackVisitor.h"

namespace Redneck
{
	Interpreter::Interpreter()
	{
		_stackVisitor = new StackVisitor(_expressionStack, _valueStack);
	}

	Interpreter::~Interpreter()
	{
		delete _stackVisitor;
	}

	Expression* Interpreter::CreateExpressions(const string& s)
	{
		Parser parser;
		return parser.CreateExpressions(s);
	}

	void Interpreter::Interpret(Expression* expression)
	{
		ByteCodeId byteCodeId = expression->GetByteCodeId();
		expression->Accept(*_stackVisitor);

		switch (byteCodeId)
		{
		case NUMEXP:
			break;
		case OPEXP:
			Interpret(Stack_Pop<Expression*>(_expressionStack));
			Interpret(Stack_Pop<Expression*>(_expressionStack));
			int b = Stack_Pop<int>(_valueStack);
			int a = Stack_Pop<int>(_valueStack);
			int op = Stack_Pop<int>(_valueStack);
			switch (op)
			{
			case '+':
				_valueStack.push(a + b);
				break;
			case '-':
				_valueStack.push(a - b);
				break;
			case '*':
				_valueStack.push(a * b);
				break;
			case '/':
				_valueStack.push(a / b);
				break;
			case '%':
				_valueStack.push(a % b);
				break;
			case '^':
				_valueStack.push(a ^ b);
				break;
			}

		}
	}

	template<class T> T Interpreter::Stack_Pop(stack<T>& stack)
	{
		if (stack.empty())
		{
			//throw StackError();
		}
		T out = stack.top();
		stack.pop();
		return out;
	}
}