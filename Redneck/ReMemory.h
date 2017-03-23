#pragma once

#include "ReDataType.h"

namespace Redneck
{
	class Memory
	{
	private:
		unordered_map<string, DataType*> _variables;
	public:
		Memory();
		virtual ~Memory();

		void Declare(const string& name, DataType* value);
		void Assign(const string& name, DataType* value);
		DataType* Get(const string& name);
		void Clear();
	};
}