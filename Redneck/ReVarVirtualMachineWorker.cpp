#include "stdafx.h"
#include "ReVarVirtualMachineWorker.h"
#include "ReInstruction.h"
#include "ReNullDataType.h"
#include "ReVirtualMachine.h"

namespace Redneck
{
	unsigned VarVirtualMachineWorker::ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction, unsigned instructionIndex)
	{
		virtualMachine->GetMemory().Declare(instruction->GetValue(), new NullDataType());
		instructionIndex++;
		return instructionIndex;
	}
}