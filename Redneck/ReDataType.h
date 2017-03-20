#pragma once

//#include "ReIntDataType.h"

namespace Redneck
{
	class DataType
	{
	private:
	protected:
	public:
		DataType()
		{

		}

		virtual DataType* operator+(const DataType& dt) = 0;
		virtual DataType* operator-(const DataType& dt) = 0;
		virtual DataType* operator/(const DataType& dt) = 0;
		virtual DataType* operator*(const DataType& dt) = 0;
		virtual bool operator>(const DataType& dt) = 0;
		virtual bool operator<(const DataType& dt) = 0;
		virtual bool operator==(const DataType& dt) = 0;
		virtual DataType* operator=(const DataType& dt) = 0;

		//static DataType& Create(int data)
		//{
		//	return IntDataType(data);
		//}
		//inline const T& GetData() const { return _data; }
	};
}