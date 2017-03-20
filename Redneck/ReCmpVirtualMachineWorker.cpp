#include "stdafx.h"
#include "ReCmpVirtualMachineWorker.h"
#include "ReInstruction.h"
#include "ReVirtualMachine.h"

namespace Redneck
{
	void CmpVirtualMachineWorker::ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction)
	{
		DataType* condition = virtualMachine->GetStack().top();
		virtualMachine->GetStack().pop();
	}
}