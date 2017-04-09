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

		virtual unsigned ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction, unsigned instructionIndex) = 0;
	};
}