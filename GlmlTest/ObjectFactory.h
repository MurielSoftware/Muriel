#pragma once

#include "Mat3x3.h"

using namespace Glml;

namespace GlmlTest
{
	Mat3x3& CreateMat3x3(float n0, float n1, float n2, float n3, float n4, float n5, float n6, float n7, float n8) 
	{
		Mat3x3 m;
		
		m[0] = n0;
		m[1] = n1;
		m[2] = n2;
		
		m[3] = n3;
		m[4] = n4;
		m[5] = n5;

		m[6] = n6;
		m[7] = n7;
		m[8] = n8;

		return m;
	}
}