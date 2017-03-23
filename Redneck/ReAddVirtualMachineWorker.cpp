#include "stdafx.h"
#include "ReAddVirtualMachineWorker.h"
#include "ReVirtualMachine.h"

namespace Redneck
{
	void AddVirtualMachineWorker::ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction)
	{
		DataType* rhs = virtualMachine->GetStack().top();
		virtualMachine->GetStack().pop();
		DataType* lhs = virtualMachine->GetStack().top();
		virtualMachine->GetStack().pop();
		
		virtualMachine->GetStack().push(*lhs + *rhs);
		
		delete rhs;
		delete lhs;
	}
}