#include "stdafx.h"
#include "ReMemory.h"

namespace Redneck
{
	Memory::Memory()
	{

	}

	Memory::~Memory()
	{
		Clear();
	}

	void Memory::Declare(const string& name, DataType* value)
	{
		_variables.insert(pair<string, DataType*>(name, value));
	}

	void Memory::Assign(const string& name, DataType* value)
	{
		_variables[name] = value;
	}

	DataType* Memory::Get(const string& name)
	{
		return _variables[name];
	}

	void Memory::Clear()
	{
		for (pair<string, DataType*> variable : _variables)
		{
			delete variable.second;
		}
		_variables.clear();
	}
}