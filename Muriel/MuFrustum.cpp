#include "stdafx.h"
#include "MuFrustum.h"

namespace Muriel
{
	Frustum::Frustum()
	{
	}

	Frustum::~Frustum()
	{
	}

	void Frustum::CalculateFrustum(Mat4x4 viewProjMatrix)
	{
		//float proj[16];
		//float view[16];
		//float clip[16];
		float t;

		//glGetFloatv(GL_PROJECTION_MATRIX, proj);
		//glGetFloatv(GL_MODELVIEW_MATRIX, view);

		//	Matrix4 clip = view * projection;

		//clip[0] = view[0] * proj[0] + view[1] * proj[4] + view[2] * proj[8] + view[3] * proj[12];
		//clip[1] = view[0] * proj[1] + view[1] * proj[5] + view[2] * proj[9] + view[3] * proj[13];
		//clip[2] = view[0] * proj[2] + view[1] * proj[6] + view[2] * proj[10] + view[3] * proj[14];
		//clip[3] = view[0] * proj[3] + view[1] * proj[7] + view[2] * proj[11] + view[3] * proj[15];

		//clip[4] = view[4] * proj[0] + view[5] * proj[4] + view[6] * proj[8] + view[7] * proj[12];
		//clip[5] = view[4] * proj[1] + view[5] * proj[5] + view[6] * proj[9] + view[7] * proj[13];
		//clip[6] = view[4] * proj[2] + view[5] * proj[6] + view[6] * proj[10] + view[7] * proj[14];
		//clip[7] = view[4] * proj[3] + view[5] * proj[7] + view[6] * proj[11] + view[7] * proj[15];

		//clip[8] = view[8] * proj[0] + view[9] * proj[4] + view[10] * proj[8] + view[11] * proj[12];
		//clip[9] = view[8] * proj[1] + view[9] * proj[5] + view[10] * proj[9] + view[11] * proj[13];
		//clip[10] = view[8] * proj[2] + view[9] * proj[6] + view[10] * proj[10] + view[11] * proj[14];
		//clip[11] = view[8] * proj[3] + view[9] * proj[7] + view[10] * proj[11] + view[11] * proj[15];

		//clip[12] = view[12] * proj[0] + view[13] * proj[4] + view[14] * proj[8] + view[15] * proj[12];
		//clip[13] = view[12] * proj[1] + view[13] * proj[5] + view[14] * proj[9] + view[15] * proj[13];
		//clip[14] = view[12] * proj[2] + view[13] * proj[6] + view[14] * proj[10] + view[15] * proj[14];
		//clip[15] = view[12] * proj[3] + view[13] * proj[7] + view[14] * proj[11] + view[15] * proj[15];

		// right plane
		_planes[0][0] = viewProjMatrix[3] - viewProjMatrix[0];
		_planes[0][1] = viewProjMatrix[7] - viewProjMatrix[4];
		_planes[0][2] = viewProjMatrix[11] - viewProjMatrix[8];
		_planes[0][3] = viewProjMatrix[15] - viewProjMatrix[12];

		t = sqrtf(_planes[0][0] * _planes[0][0] + _planes[0][1] * _planes[0][1] + _planes[0][2] * _planes[0][2]);
		_planes[0][0] /= t;
		_planes[0][1] /= t;
		_planes[0][2] /= t;
		_planes[0][3] /= t;

		// left plane
		_planes[1][0] = viewProjMatrix[3] + viewProjMatrix[0];
		_planes[1][1] = viewProjMatrix[7] + viewProjMatrix[4];
		_planes[1][2] = viewProjMatrix[11] + viewProjMatrix[8];
		_planes[1][3] = viewProjMatrix[15] + viewProjMatrix[12];

		t = sqrtf(_planes[1][0] * _planes[1][0] + _planes[1][1] * _planes[1][1] + _planes[1][2] * _planes[1][2]);
		_planes[1][0] /= t;
		_planes[1][1] /= t;
		_planes[1][2] /= t;
		_planes[1][3] /= t;

		// bottom plane
		_planes[2][0] = viewProjMatrix[3] + viewProjMatrix[1];
		_planes[2][1] = viewProjMatrix[7] + viewProjMatrix[5];
		_planes[2][2] = viewProjMatrix[11] + viewProjMatrix[9];
		_planes[2][3] = viewProjMatrix[15] + viewProjMatrix[13];

		t = sqrtf(_planes[2][0] * _planes[2][0] + _planes[2][1] * _planes[2][1] + _planes[2][2] * _planes[2][2]);
		_planes[2][0] /= t;
		_planes[2][1] /= t;
		_planes[2][2] /= t;
		_planes[2][3] /= t;

		// top plane
		_planes[3][0] = viewProjMatrix[3] - viewProjMatrix[1];
		_planes[3][1] = viewProjMatrix[7] - viewProjMatrix[5];
		_planes[3][2] = viewProjMatrix[11] - viewProjMatrix[9];
		_planes[3][3] = viewProjMatrix[15] - viewProjMatrix[13];

		t = sqrtf(_planes[3][0] * _planes[3][0] + _planes[3][1] * _planes[3][1] + _planes[3][2] * _planes[3][2]);
		_planes[3][0] /= t;
		_planes[3][1] /= t;
		_planes[3][2] /= t;
		_planes[3][3] /= t;

		// far plane
		_planes[4][0] = viewProjMatrix[3] - viewProjMatrix[2];
		_planes[4][1] = viewProjMatrix[7] - viewProjMatrix[6];
		_planes[4][2] = viewProjMatrix[11] - viewProjMatrix[10];
		_planes[4][3] = viewProjMatrix[15] - viewProjMatrix[14];

		t = sqrtf(_planes[4][0] * _planes[4][0] + _planes[4][1] * _planes[4][1] + _planes[4][2] * _planes[4][2]);
		_planes[4][0] /= t;
		_planes[4][1] /= t;
		_planes[4][2] /= t;
		_planes[4][3] /= t;

		// near plane
		_planes[5][0] = viewProjMatrix[3] + viewProjMatrix[2];
		_planes[5][1] = viewProjMatrix[7] + viewProjMatrix[6];
		_planes[5][2] = viewProjMatrix[11] + viewProjMatrix[10];
		_planes[5][3] = viewProjMatrix[15] + viewProjMatrix[14];

		t = sqrtf(_planes[5][0] * _planes[5][0] + _planes[5][1] * _planes[5][1] + _planes[5][2] * _planes[5][2]);
		_planes[5][0] /= t;
		_planes[5][1] /= t;
		_planes[5][2] /= t;
		_planes[5][3] /= t;
	}

	bool Frustum::PointInFrustum(float x, float y, float z)
	{
		for (unsigned i = 0; i < 6; i++)
		{
			if (_planes[i][0] * x + _planes[i][1] * y + _planes[i][2] * z + _planes[i][3] <= 0)
			{
				return false;
			}
		}
		return true;
	}

	bool Frustum::SphereInFrustum(float x, float y, float z, float r)
	{
		for (unsigned i = 0; i < 6; i++)
		{
			if (_planes[i][0] * x + _planes[i][1] * y + _planes[i][2] * z + _planes[i][3] <= -r)
			{
				return false;
			}
		}
		return true;
	}

	bool Frustum::CubeInFrustum(float x, float y, float z, float size)
	{
		for (unsigned i = 0; i < 6; i++)
		{
			if (_planes[i][0] * (x - size) + _planes[i][1] * (y - size) + _planes[i][2] * (z - size) + _planes[i][3] > 0)
			{
				continue;
			}
			if (_planes[i][0] * (x + size) + _planes[i][1] * (y - size) + _planes[i][2] * (z - size) + _planes[i][3] > 0)
			{
				continue;
			}
			if (_planes[i][0] * (x - size) + _planes[i][1] * (y + size) + _planes[i][2] * (z - size) + _planes[i][3] > 0)
			{
				continue;
			}
			if (_planes[i][0] * (x + size) + _planes[i][1] * (y + size) + _planes[i][2] * (z - size) + _planes[i][3] > 0)
			{
				continue;
			}
			if (_planes[i][0] * (x - size) + _planes[i][1] * (y - size) + _planes[i][2] * (z + size) + _planes[i][3] > 0)
			{
				continue;
			}
			if (_planes[i][0] * (x + size) + _planes[i][1] * (y - size) + _planes[i][2] * (z + size) + _planes[i][3] > 0)
			{
				continue;
			}
			if (_planes[i][0] * (x - size) + _planes[i][1] * (y + size) + _planes[i][2] * (z + size) + _planes[i][3] > 0)
			{
				continue;
			}
			if (_planes[i][0] * (x + size) + _planes[i][1] * (y + size) + _planes[i][2] * (z + size) + _planes[i][3] > 0)
			{
				continue;
			}
			return false;
		}
		return true;
	}
}