#include "stdafx.h"
#include "ReDivVirtualMachineWorker.h"

namespace Redneck
{
	void DivVirtualMachineWorker::ProcessInstruction(stack<IStackData*>& stack, Instruction* instruction)
	{
		IStackData* rhs = stack.top();
		stack.pop();
		IStackData* lhs = stack.top();
		stack.pop();
		stack.push(new StackData<int>(lhs->GetNumber() / rhs->GetNumber()));
	}
}