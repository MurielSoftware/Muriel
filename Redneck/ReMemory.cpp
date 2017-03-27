#include "stdafx.h"
#include "ReMemory.h"
#include "ReInvalidOperationException.h"

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
		if (_variables.find(name) != _variables.end())
		{
			throw InvalidOperationException();
		}
		_variables.insert(pair<string, DataType*>(name, value));
	}

	void Memory::Assign(const string& name, DataType* value)
	{
		if (_variables.find(name) == _variables.end())
		{
			throw InvalidOperationException();
		}
		_variables[name] = value;
	}

	DataType* Memory::Get(const string& name)
	{
		if (_variables.find(name) == _variables.end())
		{
			throw InvalidOperationException();
		}
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