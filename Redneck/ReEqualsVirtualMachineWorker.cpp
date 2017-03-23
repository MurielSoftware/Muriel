#include "stdafx.h"
#include "ReEqualsVirtualMachineWorker.h"
#include "ReInstruction.h"
#include "ReVirtualMachine.h"

namespace Redneck
{
	void EqualsVirtualMachineWorker::ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction)
	{
		DataType* rhs = virtualMachine->GetStack().top();
		virtualMachine->GetStack().pop();
		DataType* lhs = virtualMachine->GetStack().top();
		virtualMachine->GetStack().pop();

		virtualMachine->GetStack().push(*rhs == *lhs);
	}
}