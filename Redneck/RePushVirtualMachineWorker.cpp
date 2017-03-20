#include "stdafx.h"
#include "RePushVirtualMachineWorker.h"
#include "ReInstruction.h"
#include "ReIntDataType.h"

namespace Redneck
{
	void PushVirtualMachineWorker::ProcessInstruction(stack<DataType*>& stack, Memory& memory, Instruction* instruction)
	{
		DataType* dt = new IntDataType(stoi(instruction->GetValue()));
		stack.push(dt);
		//stack.push();
		//stack.push(new StackData<int>(stoi(instruction->GetValue())));
	}
}