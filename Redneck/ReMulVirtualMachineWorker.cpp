#include "stdafx.h"
#include "ReMulVirtualMachineWorker.h"

namespace Redneck
{
	void MulVirtualMachineWorker::ProcessInstruction(stack<DataType*>& stack, Memory& memory, Instruction* instruction)
	{
		DataType* rhs = stack.top();
		stack.pop();
		DataType* lhs = stack.top();
		stack.pop();

		stack.push(*rhs * *lhs);

		delete rhs;
		delete lhs;
	}
}