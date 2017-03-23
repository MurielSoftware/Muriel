#include "stdafx.h"
#include "ReBooleanDataType.h"
#include "ReInvalidOperationException.h"
#include "ReBooleanDataType.h"

namespace Redneck
{
	BooleanDataType::BooleanDataType(bool data)
	{
		_data = data;
	}

	DataType* BooleanDataType::operator+(const DataType& dt)
	{
		throw InvalidOperationException();
	}

	DataType* BooleanDataType::operator-(const DataType& dt)
	{
		throw InvalidOperationException();
	}

	DataType* BooleanDataType::operator/(const DataType& dt)
	{
		throw InvalidOperationException();
	}

	DataType* BooleanDataType::operator*(const DataType& dt)
	{
		throw InvalidOperationException();
	}

	DataType* BooleanDataType::operator>(const DataType& dt)
	{
		return new BooleanDataType(_data > ((BooleanDataType*)&dt)->GetData());
	}

	DataType* BooleanDataType::operator<(const DataType& dt)
	{
		return new BooleanDataType(_data < ((BooleanDataType*)&dt)->GetData());
	}

	DataType* BooleanDataType::operator>=(const DataType& dt)
	{
		return new BooleanDataType(_data >= ((BooleanDataType*)&dt)->GetData());
	}

	DataType* BooleanDataType::operator<=(const DataType& dt)
	{
		return new BooleanDataType(_data <= ((BooleanDataType*)&dt)->GetData());
	}

	DataType* BooleanDataType::operator!=(const DataType& dt)
	{
		return new BooleanDataType(_data != ((BooleanDataType*)&dt)->GetData());
	}

	DataType* BooleanDataType::operator==(const DataType& dt)
	{
		return new BooleanDataType(_data == ((BooleanDataType*)&dt)->GetData());
	}

	DataType* BooleanDataType::operator=(const DataType& dt)
	{
		_data = ((BooleanDataType*)&dt)->GetData();
		return this;
	}

	string BooleanDataType::ToString()
	{
		return _data ? "true" : "false";
	}

	DataType* BooleanDataType::Clone()
	{
		return new BooleanDataType(_data);
	}
}