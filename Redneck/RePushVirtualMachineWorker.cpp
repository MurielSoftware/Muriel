#include "stdafx.h"
#include "RePushVirtualMachineWorker.h"
#include "ReInstruction.h"

namespace Redneck
{
	void PushVirtualMachineWorker::ProcessInstruction(stack<IStackData*>& stack, Instruction* instruction)
	{
		stack.push(new StackData<int>(stoi(instruction->GetValue())));
	}
}