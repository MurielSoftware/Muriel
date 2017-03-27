#include "stdafx.h"
#include "ReIntDataType.h"
#include "ReDivideByZeroException.h"
#include "ReBooleanDataType.h"

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
		int rhs = ((IntDataType*)&dt)->GetData();
		if (rhs == 0)
		{
			throw DivideByZeroException();
		}
		return new IntDataType((int)_data / (int)rhs);
	}

	DataType* IntDataType::operator*(const DataType& dt)
	{
		return new IntDataType(_data * ((IntDataType*)&dt)->GetData());
	}

	DataType* IntDataType::operator>(const DataType& dt)
	{
		return new BooleanDataType(_data > ((IntDataType*)&dt)->GetData());
	}

	DataType* IntDataType::operator<(const DataType& dt)
	{
		return new BooleanDataType(_data < ((IntDataType*)&dt)->GetData());
	}

	DataType* IntDataType::operator>=(const DataType& dt)
	{
		return new BooleanDataType(_data >= ((IntDataType*)&dt)->GetData());
	}

	DataType* IntDataType::operator<=(const DataType& dt)
	{
		return new BooleanDataType(_data <= ((IntDataType*)&dt)->GetData());
	}

	DataType* IntDataType::operator!=(const DataType& dt)
	{
		return new BooleanDataType(_data != ((IntDataType*)&dt)->GetData());
	}

	DataType* IntDataType::operator==(const DataType& dt)
	{
		return new BooleanDataType(_data == ((IntDataType*)&dt)->GetData());
	}

	DataType* IntDataType::operator=(const DataType& dt)
	{
		_data = ((IntDataType*)&dt)->GetData();
		return this;
	}

	string IntDataType::ToString()
	{
		return std::to_string(_data);
	}

	DataType* IntDataType::Clone()
	{
		return new IntDataType(_data);
	}
}