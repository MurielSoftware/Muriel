#pragma once

#include "ReByteCode.h"

namespace Redneck
{
	class InstructionGenerator
	{
	private:
		void DoGenerate(list<Instruction*>& instructions, Expression* expression);
		void AddInstruction(list<Instruction*>& instructions, ByteCode byteCode, const string& value);
	public:
		InstructionGenerator();
		virtual ~InstructionGenerator();

		list<Instruction*> Generate(list<Expression*> expressions);
	};
}