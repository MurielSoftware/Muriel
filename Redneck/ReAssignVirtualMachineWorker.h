#pragma once

#include "ReVirtualMachineWorker.h"

namespace Redneck
{
	class AssignVirtualMachineWorker : public VirtualMachineWorker
	{
	public:
		void ProcessInstruction(stack<DataType*>& stack, Memory& memory, Instruction* instruction);
	};
}