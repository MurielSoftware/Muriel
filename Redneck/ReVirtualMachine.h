#pragma once

#include "ReCommon.h"
#include "ReVirtualMachineWorker.h"
#include "ReInstruction.h"
#include "ReMemory.h"

namespace Redneck
{
	class VirtualMachine
	{
	private:
		static map<ByteCode, VirtualMachineWorker*> _virtualMachineWorkers;
		static map<ByteCode, VirtualMachineWorker*> CreateVirtualMachineWorkers();
		stack<DataType*> _stack;
		Memory _memory;
		vector<Instruction*> _instructions;
	public:
		VirtualMachine();
		~VirtualMachine();

		void Execute(vector<Instruction*> instructions);

		inline Memory& GetMemory() { return _memory; }
		inline stack<DataType*>& GetStack() { return _stack; }
		inline vector<Instruction*>& GetInstructions() { return _instructions; }
	};
}
