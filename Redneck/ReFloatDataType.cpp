#include "stdafx.h"
#include "ReFloatDataType.h"
#include "ReDivideByZeroException.h"
#include "ReBooleanDataType.h"

namespace Redneck
{
	FloatDataType::FloatDataType(float data)
	{
		_data = data;
	}

	DataType* FloatDataType::operator+(const DataType& dt)
	{
		return new FloatDataType(_data + ((FloatDataType*)&dt)->GetData());
	}

	DataType* FloatDataType::operator-(const DataType& dt)
	{
		return new FloatDataType(_data - ((FloatDataType*)&dt)->GetData());
	}

	DataType* FloatDataType::operator/(const DataType& dt)
	{
		float rhs = ((FloatDataType*)&dt)->GetData();
		if (rhs == 0.0f)
		{
			throw DivideByZeroException();
		}
		return new FloatDataType(_data / rhs);
	}

	DataType* FloatDataType::operator*(const DataType& dt)
	{
		return new FloatDataType(_data * ((FloatDataType*)&dt)->GetData());
	}

	DataType* FloatDataType::operator>(const DataType& dt)
	{
		return new BooleanDataType(_data > ((FloatDataType*)&dt)->GetData());
	}

	DataType* FloatDataType::operator<(const DataType& dt)
	{
		return new BooleanDataType(_data < ((FloatDataType*)&dt)->GetData());
	}

	DataType* FloatDataType::operator>=(const DataType& dt)
	{
		return new BooleanDataType(_data >= ((FloatDataType*)&dt)->GetData());
	}

	DataType* FloatDataType::operator<=(const DataType& dt)
	{
		return new BooleanDataType(_data <= ((FloatDataType*)&dt)->GetData());
	}

	DataType* FloatDataType::operator!=(const DataType& dt)
	{
		return new BooleanDataType(_data != ((FloatDataType*)&dt)->GetData());
	}

	DataType* FloatDataType::operator==(const DataType& dt)
	{
		return new BooleanDataType(_data == ((FloatDataType*)&dt)->GetData());
	}

	DataType* FloatDataType::operator=(const DataType& dt)
	{
		_data = ((FloatDataType*)&dt)->GetData();
		return this;
	}
}