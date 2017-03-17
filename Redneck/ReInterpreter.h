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
		//stack<Expression*> _expressionStack;
		//stack<int> _valueStack;
		//StackVisitor* _stackVisitor;
		Parser* _parser;
		InstructionGenerator* _instructionGenerator;
		VirtualMachine* _virtualMachine;
		//template<class T> T Stack_Pop(stack<T>& stack);
	public:
		Interpreter();
		virtual ~Interpreter();

		void Interpret(const string& s);
		//void Interpret(Expression* expression);
	};
}