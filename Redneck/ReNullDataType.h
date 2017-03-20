#pragma once

#include "ReDataType.h"

namespace Redneck
{
	class NullDataType : public DataType
	{
	private:
	public:
		NullDataType();

		virtual DataType* operator+(const DataType& dt);
		virtual DataType* operator-(const DataType& dt);
		virtual DataType* operator/(const DataType& dt);
		virtual DataType* operator*(const DataType& dt);
		virtual bool operator>(const DataType& dt);
		virtual bool operator<(const DataType& dt);
		virtual bool operator==(const DataType& dt);
		virtual DataType* operator=(const DataType& dt);

		inline int GetData() { throw ""; }
	};
}