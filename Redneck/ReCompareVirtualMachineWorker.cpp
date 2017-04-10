#include "stdafx.h"
#include "ReCompareVirtualMachineWorker.h"
#include "ReInstruction.h"
#include "ReVirtualMachine.h"

namespace Redneck
{
	unsigned CompareVirtualMachineWorker::ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction, unsigned instructionIndex)
	{
		DataType* rhs = virtualMachine->GetStack().top();
		virtualMachine->GetStack().pop();
		DataType* lhs = virtualMachine->GetStack().top();
		virtualMachine->GetStack().pop();

		switch (instruction->GetByteCode())
		{
		case EQUALS:
			virtualMachine->GetStack().push(*rhs == *lhs);
			break;
		case NEQUALS:
			virtualMachine->GetStack().push(*rhs != *lhs);
			break;
		case GRT:
			virtualMachine->GetStack().push(*rhs > *lhs);
			break;
		case GRTE:
			virtualMachine->GetStack().push(*rhs >= *lhs);
			break;
		case LS:
			virtualMachine->GetStack().push(*rhs < *lhs);
			break;
		case LSE:
			virtualMachine->GetStack().push(*rhs <= *lhs);
			break;
		}
		instructionIndex++;
		delete rhs;
		delete lhs;
		return instructionIndex;
	}
}