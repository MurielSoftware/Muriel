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
#include "ReEqualsVirtualMachineWorker.h"
#include "ReLoadVirtualMachineWorker.h"
#include "ReSkipVirtualMachineWorker.h"

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
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::EQUALS, new EqualsVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::LOAD, new LoadVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::END, new SkipVirtualMachineWorker()));
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
		_instructions = instructions;

		for (Instruction* instruction : _instructions)
		{
			_virtualMachineWorkers[instruction->GetByteCode()]->ProcessInstruction(this, instruction);
		}
		_memory.Clear();
	}
}