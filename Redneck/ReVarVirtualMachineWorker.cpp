#include "stdafx.h"
#include "ReVarVirtualMachineWorker.h"
#include "ReInstruction.h"
#include "ReNullDataType.h"

namespace Redneck
{
	void VarVirtualMachineWorker::ProcessInstruction(stack<DataType*>& stack, Memory& memory, Instruction* instruction)
	{
		memory.Declare(instruction->GetValue(), new NullDataType());
	}
}