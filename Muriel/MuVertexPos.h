#pragma once

#include "Vec3.h"
#include "Vec2.h"

using namespace Glml;

namespace Muriel
{
	class VertexPos
	{
	private:
		Vec3 _position;
	public:
		VertexPos() {}

		VertexPos(Vec3 position)
			:_position(position)
		{}

		inline void SetPosition(const Vec3& position) { _position = position; }
	};
}