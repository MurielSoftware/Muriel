#pragma once

#include "ReDataType.h"

namespace Redneck
{
	class IntDataType : public DataType
	{
	private:
		int _data;
	public:
		IntDataType(int data);

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

		inline int GetData() { return _data; }
	};
}