#include "stdafx.h"
#include "ReDivVirtualMachineWorker.h"
#include "ReVirtualMachine.h"

namespace Redneck
{
	void DivVirtualMachineWorker::ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction)
	{
		DataType* rhs = virtualMachine->GetStack().top();
		virtualMachine->GetStack().pop();
		DataType* lhs = virtualMachine->GetStack().top();
		virtualMachine->GetStack().pop();

		virtualMachine->GetStack().push(*lhs / *rhs);

		delete rhs;
		delete lhs;
	}
}