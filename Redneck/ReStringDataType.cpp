#include "stdafx.h"
#include "ReStringDataType.h"
#include "ReInvalidOperationException.h"

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

	bool StringDataType::operator>(const DataType& dt)
	{
		return _data > ((StringDataType*)&dt)->GetData();
	}

	bool StringDataType::operator<(const DataType& dt)
	{
		return _data < ((StringDataType*)&dt)->GetData();
	}

	bool StringDataType::operator==(const DataType& dt)
	{
		return _data == ((StringDataType*)&dt)->GetData();
	}

	DataType* StringDataType::operator=(const DataType& dt)
	{
		_data = ((StringDataType*)&dt)->GetData();
		return this;
	}
}