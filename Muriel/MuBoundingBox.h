#pragma once

#include "Vec3.h"
#include "MuVertexPos.h"

using namespace Glml;

namespace Muriel
{
	class BoundingBox
	{
	private:
		Vec3 _center;
		Vec3 _halfSize;

		static VertexPos* _vertices;
		static unsigned short* _indices;
		static VertexBuffer* _vertexBuffer;
		static IndexBuffer* _indexBuffer;
	public:
		BoundingBox();
		BoundingBox(Vec3 center, Vec3 halfSize);
		virtual ~BoundingBox();

		static VertexPos* CreateVertices();
		static unsigned short* CreateIndices();

		inline const Vec3& GetMin() const { return _center - _halfSize; }
		inline const Vec3& GetMax() const { return _center + _halfSize; }
		inline const Vec3& GetCenter() const { return _center; }
		inline const Vec3& GetHalfSize() const { return _halfSize; }
		inline void SetCenter(const Vec3& center) { _center = center; }
		inline void SetHalfSize(const Vec3& halfSize) { _halfSize = halfSize; }

		void Render();
	};
}