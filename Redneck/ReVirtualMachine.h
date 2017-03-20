#pragma once

#include "ReByteCode.h"
#include "ReVirtualMachineWorker.h"
#include "ReInstruction.h"
#include "ReMemory.h"

#include <list>
#include <map>
using namespace std;

namespace Redneck
{
	class VirtualMachine
	{
	private:
		static map<ByteCode, VirtualMachineWorker*> _virtualMachineWorkers;
		static map<ByteCode, VirtualMachineWorker*> CreateVirtualMachineWorkers();
		stack<DataType*> _stack;
		Memory _memory;
	public:
		VirtualMachine();
		~VirtualMachine();

		void Execute(list<Instruction*> instructions);
	};
}
