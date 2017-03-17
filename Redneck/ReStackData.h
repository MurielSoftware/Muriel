#pragma once

#include "ReIStackData.h"
#include <string>

using namespace std;

namespace Redneck
{
	template<class T> class StackData : public IStackData
	{
	private:
		T _data;
	public:
		StackData()
		{

		}

		StackData(const T& data)
		{
			_data = data;
		}

		inline int GetNumber() { return (int)_data; }

		virtual ~StackData()
		{

		}
	};
}