#include "stdafx.h"
#include "ReAddVirtualMachineWorker.h"

namespace Redneck
{
	void AddVirtualMachineWorker::ProcessInstruction(stack<IStackData*>& stack, Instruction* instruction)
	{
		IStackData* rhs = stack.top();
		stack.pop();
		IStackData* lhs = stack.top();
		stack.pop();
		stack.push(new StackData<int>(lhs->GetNumber() + rhs->GetNumber()));
	}
}