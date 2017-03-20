#pragma once

#include "stdafx.h"

namespace Redneck
{
	class REDNECK_API Interpreter
	{
	private:
		Parser* _parser;
		InstructionGenerator* _instructionGenerator;
		VirtualMachine* _virtualMachine;
	public:
		Interpreter();
		virtual ~Interpreter();

		void Interpret(const string& s);
	};
}