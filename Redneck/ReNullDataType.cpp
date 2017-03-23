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

	DataType* NullDataType::operator>(const DataType& dt)
	{
		throw NullPointerException();
	}

	DataType* NullDataType::operator<(const DataType& dt)
	{
		throw NullPointerException();
	}

	DataType* NullDataType::operator>=(const DataType& dt)
	{
		throw NullPointerException();
	}

	DataType* NullDataType::operator<=(const DataType& dt)
	{
		throw NullPointerException();
	}

	DataType* NullDataType::operator!=(const DataType& dt)
	{
		throw NullPointerException();
	}

	DataType* NullDataType::operator==(const DataType& dt)
	{
		throw NullPointerException();
	}

	DataType* NullDataType::operator=(const DataType& dt)
	{
		throw NullPointerException();
	}

	string NullDataType::ToString()
	{
		throw NullPointerException();
	}

	DataType* NullDataType::Clone()
	{
		throw NullPointerException();
	}
}