#pragma once

#include "ReByteCode.h"

namespace Redneck
{
	class InstructionGenerator
	{
	private:
		string GetJumpAddress(const string& name, int depth);
		void GenerateDeclaration(vector<Instruction*>& instructions, Expression* expression, unsigned depth);
		void GenerateAssociation(vector<Instruction*>& instructions, Expression* expression, unsigned depth);
		void GenerateValue(vector<Instruction*>& instructions, Expression* expression, unsigned depth);
		void GenerateIdentifier(vector<Instruction*>& instructions, Expression* expression, unsigned depth);
		void GenerateBinaryOperation(vector<Instruction*>& instructions, Expression* expression, unsigned depth);
		void GenerateIf(vector<Instruction*>& instructions, Expression* expression, unsigned depth);
		void GenerateWhile(vector<Instruction*>& instructions, Expression* expression, unsigned depth);

		void DoGenerateInner(vector<Instruction*>& instructions, list<Expression*> expressions, unsigned depth);
		void DoGenerate(vector<Instruction*>& instructions, Expression* expression, unsigned depth);
		void AddInstruction(vector<Instruction*>& instructions, ByteCode byteCode, const string& value);
	public:
		InstructionGenerator();
		virtual ~InstructionGenerator();

		vector<Instruction*> Generate(list<Expression*> expressions);
	};
}