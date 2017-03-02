#pragma once

#include "Vec3.h"

using namespace Glml;

namespace Muriel
{
	class BoundingBox
	{
	private:
		Vec3 _center;
		Vec3 _halfSize;
	public:
		BoundingBox();
		BoundingBox(Vec3 center, Vec3 halfSize);
		virtual ~BoundingBox();

		inline const Vec3& GetMin() const { return _center - _halfSize; }
		inline const Vec3& GetMax() const { return _center + _halfSize; }
	};
}