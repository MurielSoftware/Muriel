#include "stdafx.h"
#include "ReLoadVirtualMachineWorker.h"
#include "ReVirtualMachine.h"

namespace Redneck
{
	void LoadVirtualMachineWorker::ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction)
	{
		virtualMachine->GetStack().push(virtualMachine->GetMemory().Get(instruction->GetValue())->Clone());
	}
}