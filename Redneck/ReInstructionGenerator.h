#pragma once

#include <list>

using namespace std;

namespace Redneck
{
	class InstructionGenerator
	{
	private:
		void DoGenerate(list<Instruction*>& instructions, Expression* expression);
	public:
		InstructionGenerator();
		virtual ~InstructionGenerator();

		list<Instruction*> Generate(Expression* expression);
	};
}