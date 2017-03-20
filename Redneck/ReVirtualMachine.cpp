#include "stdafx.h"
#include "ReVirtualMachine.h"
#include "ReInstruction.h"
#include "RePushVirtualMachineWorker.h"
#include "ReAddVirtualMachineWorker.h"
#include "ReMulVirtualMachineWorker.h"
#include "ReSubVirtualMachineWorker.h"
#include "ReDivVirtualMachineWorker.h"
#include "ReVarVirtualMachineWorker.h"
#include "ReAssignVirtualMachineWorker.h"
#include "ReCmpVirtualMachineWorker.h"

namespace Redneck
{
	map<ByteCode, VirtualMachineWorker*> VirtualMachine::_virtualMachineWorkers = CreateVirtualMachineWorkers();

	map<ByteCode, VirtualMachineWorker*> VirtualMachine::CreateVirtualMachineWorkers()
	{
		map<ByteCode, VirtualMachineWorker*> map;
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::PUSH, new PushVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::ADD, new AddVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::SUB, new SubVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::MULT, new MulVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::DIV, new DivVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::VAR, new VarVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::ASN, new AssignVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::CMP, new CmpVirtualMachineWorker()));

		return map;
	}

	VirtualMachine::VirtualMachine()
	{

	}

	VirtualMachine::~VirtualMachine()
	{

	}

	void VirtualMachine::Execute(list<Instruction*> instructions)
	{
		for (Instruction* instruction : instructions)
		{
			_virtualMachineWorkers[instruction->GetByteCode()]->ProcessInstruction(_stack, _memory, instruction);
		}
		_memory.Clear();
	}
}