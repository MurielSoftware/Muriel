#include "stdafx.h"
#include "ReNullDataType.h"
#include "ReNullPointerException.h"

namespace Redneck
{
	NullDataType::NullDataType()
	{
	}

	DataType* NullDataType::operator+(const DataType& dt)
	{
		throw NullPointerException();
	}

	DataType* NullDataType::operator-(const DataType& dt)
	{
		throw NullPointerException();
	}

	DataType* NullDataType::operator/(const DataType& dt)
	{
		throw NullPointerException();
	}

	DataType* NullDataType::operator*(const DataType& dt)
	{
		throw NullPointerException();
	}

	bool NullDataType::operator>(const DataType& dt)
	{
		throw NullPointerException();
	}

	bool NullDataType::operator<(const DataType& dt)
	{
		throw NullPointerException();
	}

	bool NullDataType::operator==(const DataType& dt)
	{
		throw NullPointerException();
	}

	DataType* NullDataType::operator=(const DataType& dt)
	{
		throw NullPointerException();
	}
}