#pragma once

#include "Mat3x3.h"

using namespace Glml;

namespace GlmlTest
{
	bool AreNumsEqual(float expected, float actual)
	{
		if ((expected == 0.0f && actual == -0.0f) || (expected == -0.0f && actual == 0.0f))
		{
			return true;
		}
		return fabsf(expected - actual) < 0.001f;
	}

	bool AreMatricesEqual(const Mat3x3& expected, const Mat3x3& actual)
	{
		for (int i = 0; i < 9; i++)
		{
			if (!AreNumsEqual(expected[i], actual[i]))
			{
				return false;
			}
		}
		return true;
	}
}