#include "stdafx.h"
#include "ReIntDataType.h"
#include "ReDivideByZeroException.h"

namespace Redneck
{
	IntDataType::IntDataType(int data)
	{
		_data = data;
	}

	DataType* IntDataType::operator+(const DataType& dt)
	{
		return new IntDataType(_data + ((IntDataType*)&dt)->GetData());
	}

	DataType* IntDataType::operator-(const DataType& dt)
	{
		return new IntDataType(_data - ((IntDataType*)&dt)->GetData());
	}

	DataType* IntDataType::operator/(const DataType& dt)
	{
		float rhs = ((IntDataType*)&dt)->GetData();
		if (rhs == 0.0f)
		{
			throw DivideByZeroException();
		}
		return new IntDataType(_data / rhs);
	}

	DataType* IntDataType::operator*(const DataType& dt)
	{
		return new IntDataType(_data * ((IntDataType*)&dt)->GetData());
	}

	bool IntDataType::operator>(const DataType& dt)
	{
		return _data > ((IntDataType*)&dt)->GetData();
	}

	bool IntDataType::operator<(const DataType& dt)
	{
		return _data < ((IntDataType*)&dt)->GetData();
	}

	bool IntDataType::operator==(const DataType& dt)
	{
		return _data == ((IntDataType*)&dt)->GetData();
	}

	DataType* IntDataType::operator=(const DataType& dt)
	{
		_data = ((IntDataType*)&dt)->GetData();
		return this;
	}
}