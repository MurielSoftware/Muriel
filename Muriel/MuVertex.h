#pragma once

#include "Vec3.h"

using namespace Glml;

namespace Muriel
{
	class Vertex
	{
	private:
		Vec3 _position;
	public:
		inline const Vec3& GetPosition() const { return _position; }
		inline void SetPosition(const Vec3& position) { _position = position; }
	};
}