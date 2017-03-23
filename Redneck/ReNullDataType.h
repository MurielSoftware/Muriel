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
		virtual DataType* operator>(const DataType& dt);
		virtual DataType* operator<(const DataType& dt);
		virtual DataType* operator<=(const DataType& dt);
		virtual DataType* operator>=(const DataType& dt);
		virtual DataType* operator!=(const DataType& dt);
		virtual DataType* operator==(const DataType& dt);
		virtual DataType* operator=(const DataType& dt);
		virtual string ToString();
		virtual DataType* Clone();

		inline int GetData() { throw ""; }
	};
}