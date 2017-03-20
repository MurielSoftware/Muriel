#include "stdafx.h"
#include "ReSubVirtualMachineWorker.h"
#include "ReVirtualMachine.h"

namespace Redneck
{
	void SubVirtualMachineWorker::ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction)
	{
		DataType* rhs = virtualMachine->GetStack().top();
		virtualMachine->GetStack().pop();
		DataType* lhs = virtualMachine->GetStack().top();
		virtualMachine->GetStack().pop();

		virtualMachine->GetStack().push(*rhs - *lhs);

		delete rhs;
		delete lhs;
	}
}