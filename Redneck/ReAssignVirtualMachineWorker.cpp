#include "stdafx.h"
#include "ReAssignVirtualMachineWorker.h"
#include "ReInstruction.h"

namespace Redneck
{
	void AssignVirtualMachineWorker::ProcessInstruction(stack<DataType*>& stack, Memory& _memory, Instruction* instruction)
	{
		DataType* value = stack.top();
		stack.pop();
		_memory.Assign(instruction->GetValue(), value);
	}
}