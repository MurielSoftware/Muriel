#pragma once

#include "ReVirtualMachineWorker.h"

namespace Redneck
{
	class PushVirtualMachineWorker : public VirtualMachineWorker
	{
	private:
		DataType* GetDataTypeValue(const string& value);
		bool IsInteger(const string& value);
		bool IsFloat(const string& value);
		bool IsBoolean(const string& value);
	public:
		unsigned ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction, unsigned instructionIndex);
	};
}