#pragma once

#include "ReDataType.h"
#include <unordered_map>
#include <string>

using namespace std;

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
		void Clear();
	};
}