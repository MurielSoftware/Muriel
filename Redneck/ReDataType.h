#pragma once

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
		virtual bool operator<=(const DataType& dt) = 0;
		virtual bool operator>=(const DataType& dt) = 0;
		virtual bool operator!=(const DataType& dt) = 0;
		virtual bool operator==(const DataType& dt) = 0;
		virtual DataType* operator=(const DataType& dt) = 0;
	};
}