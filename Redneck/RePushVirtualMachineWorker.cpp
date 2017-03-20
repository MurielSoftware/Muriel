#include "stdafx.h"
#include "RePushVirtualMachineWorker.h"
#include "ReInstruction.h"
#include "ReIntDataType.h"
#include "ReVirtualMachine.h"

namespace Redneck
{
	void PushVirtualMachineWorker::ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction)
	{
		DataType* dt = new IntDataType(stoi(instruction->GetValue()));
		virtualMachine->GetStack().push(dt);
		//stack.push();
		//stack.push(new StackData<int>(stoi(instruction->GetValue())));
	}
}