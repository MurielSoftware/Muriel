#include "stdafx.h"

#include <xmmintrin.h>

#include "SSEOperations.h"

namespace Glml
{
	void SSE_MAT3x3_MUL(const float *A, const float *B, float *C) {
		__m128 row1 = _mm_loadu_ps(&B[0]);
		__m128 row2 = _mm_loadu_ps(&B[3]);
		__m128 row3 = _mm_loadu_ps(&B[6]);
		for (int i = 0; i < 3; i++) {
			__m128 brod1 = _mm_set1_ps(A[3 * i + 0]);
			__m128 brod2 = _mm_set1_ps(A[3 * i + 1]);
			__m128 brod3 = _mm_set1_ps(A[3 * i + 2]);
			__m128 row = _mm_add_ps(
				_mm_add_ps(_mm_mul_ps(brod1, row1),_mm_mul_ps(brod2, row2)),
				_mm_mul_ps(brod3, row3)
			);
			_mm_storeu_ps(&C[3 * i], row);
		}
	}

	void SSE_MAT4x4_MUL(const float *A, const float *B, float *C) {
		__m128 row1 = _mm_loadu_ps(&B[0]);
		__m128 row2 = _mm_loadu_ps(&B[4]);
		__m128 row3 = _mm_loadu_ps(&B[8]);
		__m128 row4 = _mm_loadu_ps(&B[12]);
		for (int i = 0; i < 4; i++) {
			__m128 brod1 = _mm_set1_ps(A[4 * i + 0]);
			__m128 brod2 = _mm_set1_ps(A[4 * i + 1]);
			__m128 brod3 = _mm_set1_ps(A[4 * i + 2]);
			__m128 brod4 = _mm_set1_ps(A[4 * i + 3]);
			__m128 row = _mm_add_ps(
				_mm_add_ps(_mm_mul_ps(brod1, row1), _mm_mul_ps(brod2, row2)),
				_mm_add_ps(_mm_mul_ps(brod3, row3), _mm_mul_ps(brod4, row4))
			);
			_mm_storeu_ps(&C[4 * i], row);
		}
	}
}