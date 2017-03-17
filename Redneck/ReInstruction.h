#pragma once

#include "ReByteCode.h"
#include <string>

using namespace std;

namespace Redneck
{
	class Instruction
	{
	private:
		ByteCode _byteCode;
		string _value;
	public:
		Instruction();
		Instruction(ByteCode byteCode);
		Instruction(ByteCode byteCode, const string& value);
		virtual ~Instruction();

		inline ByteCode GetByteCode() { return _byteCode; }
		inline const string& GetValue() const { return _value; }
	};
}