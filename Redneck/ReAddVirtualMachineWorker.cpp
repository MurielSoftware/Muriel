#include "stdafx.h"
#include "ReAddVirtualMachineWorker.h"

namespace Redneck
{
	void AddVirtualMachineWorker::ProcessInstruction(stack<DataType*>& stack, Memory& memory, Instruction* instruction)
	{
		DataType* rhs = stack.top();
		stack.pop();
		DataType* lhs = stack.top();
		stack.pop();
		
		stack.push(*rhs + *lhs);
		
		delete rhs;
		delete lhs;
	}
}