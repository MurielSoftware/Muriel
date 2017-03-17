#include "stdafx.h"
#include "ReSubVirtualMachineWorker.h"

namespace Redneck
{
	void SubVirtualMachineWorker::ProcessInstruction(stack<IStackData*>& stack, Instruction* instruction)
	{
		IStackData* rhs = stack.top();
		stack.pop();
		IStackData* lhs = stack.top();
		stack.pop();
		stack.push(new StackData<int>(lhs->GetNumber() - rhs->GetNumber()));
	}
}