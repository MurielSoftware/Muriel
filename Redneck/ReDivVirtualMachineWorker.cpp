#include "stdafx.h"
#include "ReDivVirtualMachineWorker.h"

namespace Redneck
{
	void DivVirtualMachineWorker::ProcessInstruction(stack<DataType*>& stack, Memory& memory, Instruction* instruction)
	{
		DataType* rhs = stack.top();
		stack.pop();
		DataType* lhs = stack.top();
		stack.pop();

		stack.push(*rhs / *lhs);

		delete rhs;
		delete lhs;
	}
}