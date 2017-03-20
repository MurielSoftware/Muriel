#pragma once

#include "ReMemory.h"

namespace Redneck
{
	class VirtualMachineWorker
	{
	public:
		VirtualMachineWorker()
		{

		}

		virtual void ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction) = 0;
	};
}