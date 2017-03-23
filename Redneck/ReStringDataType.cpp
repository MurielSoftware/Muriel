#include "stdafx.h"
#include "ReStringDataType.h"
#include "ReInvalidOperationException.h"
#include "ReBooleanDataType.h"

namespace Redneck
{
	StringDataType::StringDataType(const string& data)
	{
		_data = data;
	}

	DataType* StringDataType::operator+(const DataType& dt)
	{
		return new StringDataType(_data + ((StringDataType*)&dt)->GetData());
	}

	DataType* StringDataType::operator-(const DataType& dt)
	{
		throw InvalidOperationException();
	}

	DataType* StringDataType::operator/(const DataType& dt)
	{
		throw InvalidOperationException();
	}

	DataType* StringDataType::operator*(const DataType& dt)
	{
		throw InvalidOperationException();
	}

	DataType* StringDataType::operator>(const DataType& dt)
	{
		return new BooleanDataType(_data > ((StringDataType*)&dt)->GetData());
	}

	DataType* StringDataType::operator<(const DataType& dt)
	{
		return new BooleanDataType(_data < ((StringDataType*)&dt)->GetData());
	}

	DataType* StringDataType::operator>=(const DataType& dt)
	{
		return new BooleanDataType(_data >= ((StringDataType*)&dt)->GetData());
	}

	DataType* StringDataType::operator<=(const DataType& dt)
	{
		return new BooleanDataType(_data <= ((StringDataType*)&dt)->GetData());
	}

	DataType* StringDataType::operator!=(const DataType& dt)
	{
		return new BooleanDataType(_data != ((StringDataType*)&dt)->GetData());
	}

	DataType* StringDataType::operator==(const DataType& dt)
	{
		return new BooleanDataType(_data == ((StringDataType*)&dt)->GetData());
	}

	DataType* StringDataType::operator=(const DataType& dt)
	{
		_data = ((StringDataType*)&dt)->GetData();
		return this;
	}

	string StringDataType::ToString()
	{
		return _data;
	}

	DataType* StringDataType::Clone()
	{
		return new StringDataType(_data);
	}
}