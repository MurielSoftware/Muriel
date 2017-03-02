#pragma once

#include "Mat4x4.h"

using namespace Glml;

namespace Muriel
{
	class Frustum
	{
	private:
		float _planes[6][4];

	public:
		Frustum();
		virtual ~Frustum();

		void CalculateFrustum(Mat4x4 viewProjMatrix);
		bool PointInFrustum(float x, float y, float z);
		bool SphereInFrustum(float x, float y, float z, float r);
		bool CubeInFrustum(float x, float y, float z, float fSize);
	};
}