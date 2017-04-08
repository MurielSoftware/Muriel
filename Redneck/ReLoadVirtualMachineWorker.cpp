#include "stdafx.h"
#include "ReLoadVirtualMachineWorker.h"
#include "ReVirtualMachine.h"

namespace Redneck
{
	unsigned LoadVirtualMachineWorker::ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction, unsigned instructionIndex)
	{
		virtualMachine->GetStack().push(virtualMachine->GetMemory().Get(instruction->GetValue())->Clone());	
		instructionIndex++;
		return instructionIndex;
	}
}