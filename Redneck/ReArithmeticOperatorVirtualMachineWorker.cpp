#include "stdafx.h"
#include "ReArithmeticOperatorVirtualMachineWorker.h"
#include "ReVirtualMachine.h"

namespace Redneck
{
	unsigned ArithmeticOperatorVirtualMachineWorker::ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction, unsigned instructionIndex)
	{
		DataType* rhs = virtualMachine->GetStack().top();
		virtualMachine->GetStack().pop();
		DataType* lhs = virtualMachine->GetStack().top();
		virtualMachine->GetStack().pop();	

		switch (instruction->GetByteCode())
		{
		case ADD:
			virtualMachine->GetStack().push(*lhs + *rhs);
			break;
		case SUB:
			virtualMachine->GetStack().push(*lhs - *rhs);
			break;
		case MULT:
			virtualMachine->GetStack().push(*lhs * *rhs);
			break;
		case DIV:
			virtualMachine->GetStack().push(*lhs / *rhs);
			break;
		}		
		instructionIndex++;
		delete rhs;
		delete lhs;
		return instructionIndex;
	}
}