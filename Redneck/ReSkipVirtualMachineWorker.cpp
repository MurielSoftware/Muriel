#include "stdafx.h"
#include "ReSkipVirtualMachineWorker.h"
#include "ReVirtualMachine.h"

namespace Redneck
{
	unsigned SkipVirtualMachineWorker::ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction, unsigned instructionIndex)
	{
		instructionIndex++;
		return instructionIndex;
	}
}