#pragma once

#include "ReDataType.h"

namespace Redneck
{
	class BooleanDataType : public DataType
	{
	private:
		bool _data;
	public:
		BooleanDataType(bool data);

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

		inline bool GetData() { return _data; }
	};
}
