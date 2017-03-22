#pragma once

#include "ReCommon.h"
#include "ReDataType.h"

namespace Redneck
{
	class StringDataType : public DataType
	{
	private:
		string _data;
	public:
		StringDataType(const string& data);
		
		virtual DataType* operator+(const DataType& dt);
		virtual DataType* operator-(const DataType& dt);
		virtual DataType* operator/(const DataType& dt);
		virtual DataType* operator*(const DataType& dt);
		virtual bool operator>(const DataType& dt);
		virtual bool operator<(const DataType& dt);
		virtual bool operator<=(const DataType& dt);
		virtual bool operator>=(const DataType& dt);
		virtual bool operator!=(const DataType& dt);
		virtual bool operator==(const DataType& dt);
		virtual DataType* operator=(const DataType& dt);

		inline const string& GetData() { return _data; }
	};
}