#include "stdafx.h"
#include "Mat4x4.h"
#include "SSEOperations.h"

namespace Glml
{
	Mat4x4::Mat4x4()
	{
		Identity();
	}

	float& Mat4x4::operator[] (int i)
	{
		return data[i];
	}

	const float& Mat4x4::operator[] (int i) const
	{
		return data[i];
	}

	Mat4x4 Mat4x4::operator*(const Mat4x4 m) const
	{
		Mat4x4 result;
		//auto t1 = std::chrono::high_resolution_clock::now();
		//result.data[0] = (m.data[0] * data[0]) + (m.data[4] * data[1]) + (m.data[8] * data[2]) + (m.data[12] * data[3]);
		//result.data[4] = (m.data[0] * data[4]) + (m.data[4] * data[5]) + (m.data[8] * data[6]) + (m.data[12] * data[7]);
		//result.data[8] = (m.data[0] * data[8]) + (m.data[4] * data[9]) + (m.data[8] * data[10]) + (m.data[12] * data[11]);
		//result.data[12] = (m.data[0] * data[12]) + (m.data[4] * data[13]) + (m.data[8] * data[14]) + (m.data[12] * data[15]);

		//result.data[1] = (m.data[1] * data[0]) + (m.data[5] * data[1]) + (m.data[9] * data[2]) + (m.data[13] * data[3]);
		//result.data[5] = (m.data[1] * data[4]) + (m.data[5] * data[5]) + (m.data[9] * data[6]) + (m.data[13] * data[7]);
		//result.data[9] = (m.data[1] * data[8]) + (m.data[5] * data[9]) + (m.data[9] * data[10]) + (m.data[13] * data[11]);
		//result.data[13] = (m.data[1] * data[12]) + (m.data[5] * data[13]) + (m.data[9] * data[14]) + (m.data[13] * data[15]);

		//result.data[2] = (m.data[2] * data[0]) + (m.data[6] * data[1]) + (m.data[10] * data[2]) + (m.data[14] * data[3]);
		//result.data[6] = (m.data[2] * data[4]) + (m.data[6] * data[5]) + (m.data[10] * data[6]) + (m.data[14] * data[7]);
		//result.data[10] = (m.data[2] * data[8]) + (m.data[6] * data[9]) + (m.data[10] * data[10]) + (m.data[14] * data[11]);
		//result.data[14] = (m.data[2] * data[12]) + (m.data[6] * data[13]) + (m.data[10] * data[14]) + (m.data[14] * data[15]);

		//result.data[3] = (m.data[3] * data[0]) + (m.data[7] * data[1]) + (m.data[11] * data[2]) + (m.data[15] * data[3]);
		//result.data[7] = (m.data[3] * data[4]) + (m.data[7] * data[5]) + (m.data[11] * data[6]) + (m.data[15] * data[7]);
		//result.data[11] = (m.data[3] * data[8]) + (m.data[7] * data[9]) + (m.data[11] * data[10]) + (m.data[15] * data[11]);
		//result.data[15] = (m.data[3] * data[12]) + (m.data[7] * data[13]) + (m.data[11] * data[14]) + (m.data[15] * data[15]);
		//auto t2 = std::chrono::high_resolution_clock::now();
		
		//auto t1 = std::chrono::high_resolution_clock::now();
		SSE_MAT4x4_MUL(m.data, data, result.data);
		//auto t2 = std::chrono::high_resolution_clock::now();
		//long long ms = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
		return result;
	}

	void Mat4x4::Identity()
	{
		data[0] = 1.0f;
		data[1] = 0.0f;
		data[2] = 0.0f;
		data[3] = 0.0f;

		data[4] = 0.0f;
		data[5] = 1.0f;
		data[6] = 0.0f;
		data[7] = 0.0f;

		data[8] = 0.0f;
		data[9] = 0.0f;
		data[10] = 1.0f;
		data[11] = 0.0f;

		data[12] = 0.0f;
		data[13] = 0.0f;
		data[14] = 0.0f;
		data[15] = 1.0f;
	}

	const float* Mat4x4::Pointer() const
	{
		return &data[0];
	}
}