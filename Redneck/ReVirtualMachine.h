#pragma once

#include "ReByteCode.h"
#include "ReVirtualMachineWorker.h"
#include "ReInstruction.h"

#include <list>
#include <map>
using namespace std;

namespace Redneck
{
	class VirtualMachine
	{
	private:
		static map<ByteCode, VirtualMachineWorker*> _virtualMachineWorkers;
		stack<IStackData*> _stack;
		unordered_map<string, IStackData*> _variableTable;

		static map<ByteCode, VirtualMachineWorker*> CreateVirtualMachineWorkers();
	public:
		VirtualMachine();
		~VirtualMachine();

		void Execute(list<Instruction*> instructions);
	};
}
