#include "stdafx.h"
#include "ReCmpVirtualMachineWorker.h"
#include "ReInstruction.h"

namespace Redneck
{
	void CmpVirtualMachineWorker::ProcessInstruction(stack<DataType*>& stack, Memory& _memory, Instruction* instruction)
	{
		DataType* condition = stack.top();
		stack.pop();
	}
}