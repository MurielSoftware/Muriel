#pragma once

#include "Vec3.h"
#include "Vec2.h"

using namespace Glml;

namespace Muriel
{
	class VertexPosNormTex
	{
	private:
		Vec3 _position;
		Vec3 _normal;
		Vec2 _texCoord;
	public:
		VertexPosNormTex() {}

		VertexPosNormTex(Vec3 position, Vec3 normal, Vec2 texCoord) 
			:_position(position), _normal(normal), _texCoord(texCoord) 
		{}
	};
}