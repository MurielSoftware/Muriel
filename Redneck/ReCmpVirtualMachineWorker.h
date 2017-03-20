#pragma once

#include "ReVirtualMachineWorker.h"

namespace Redneck
{
	class CmpVirtualMachineWorker : public VirtualMachineWorker
	{
	public:
		void ProcessInstruction(stack<DataType*>& stack, Memory& memory, Instruction* instruction);
	};
}