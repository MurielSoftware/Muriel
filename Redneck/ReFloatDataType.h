#pragma once

#include "ReDataType.h"

namespace Redneck
{
	class FloatDataType : public DataType
	{
	private:
		float _data;
	public:
		FloatDataType(float data);

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

		inline float GetData() { return _data; }
	};
}