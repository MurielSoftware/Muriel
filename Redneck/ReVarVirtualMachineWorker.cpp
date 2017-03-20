#include "stdafx.h"
#include "ReVarVirtualMachineWorker.h"
#include "ReInstruction.h"
#include "ReNullDataType.h"
#include "ReVirtualMachine.h"

namespace Redneck
{
	void VarVirtualMachineWorker::ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction)
	{
		virtualMachine->GetMemory().Declare(instruction->GetValue(), new NullDataType());
	}
}