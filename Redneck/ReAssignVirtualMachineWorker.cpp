#include "stdafx.h"
#include "ReAssignVirtualMachineWorker.h"
#include "ReInstruction.h"
#include "ReVirtualMachine.h"

namespace Redneck
{
	void AssignVirtualMachineWorker::ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction)
	{
		DataType* value = virtualMachine->GetStack().top();
		virtualMachine->GetStack().pop();
		virtualMachine->GetMemory().Assign(instruction->GetValue(), value);
	}
}