#pragma once

#include "ReDataType.h"
#include <string>

using namespace std;

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
		virtual bool operator==(const DataType& dt);
		virtual DataType* operator=(const DataType& dt);

		inline const string& GetData() { return _data; }
	};
}