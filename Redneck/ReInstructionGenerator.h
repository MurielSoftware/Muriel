#pragma once

#include "ReByteCode.h"

namespace Redneck
{
	class InstructionGenerator
	{
	private:
		void GenerateDeclaration(list<Instruction*>& instructions, Expression* expression);
		void GenerateAssociation(list<Instruction*>& instructions, Expression* expression);
		void GenerateValue(list<Instruction*>& instructions, Expression* expression);
		void GenerateIdentifier(list<Instruction*>& instructions, Expression* expression);
		void GenerateBinaryOperation(list<Instruction*>& instructions, Expression* expression);
		void GenerateIf(list<Instruction*>& instructions, Expression* expression);
		void GenerateWhile(list<Instruction*>& instructions, Expression* expression);

		void DoGenerateInner(list<Instruction*>& instructions, list<Expression*> expressions);
		void DoGenerate(list<Instruction*>& instructions, Expression* expression);
		void AddInstruction(list<Instruction*>& instructions, ByteCode byteCode, const string& value, unsigned short address = 0);
	public:
		InstructionGenerator();
		virtual ~InstructionGenerator();

		list<Instruction*> Generate(list<Expression*> expressions);
	};
}