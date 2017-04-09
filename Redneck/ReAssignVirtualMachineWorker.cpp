#include "stdafx.h"
#include "ReAssignVirtualMachineWorker.h"
#include "ReInstruction.h"
#include "ReVirtualMachine.h"

namespace Redneck
{
	unsigned AssignVirtualMachineWorker::ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction, unsigned instructionIndex)
	{
		DataType* value = virtualMachine->GetStack().top();
		virtualMachine->GetStack().pop();
		virtualMachine->GetMemory().Assign(instruction->GetValue(), value);
		instructionIndex++;
		return instructionIndex;
	}
}