#pragma once

#include "MuObject.h"
#include "MuBoundingBox.h"

namespace Muriel
{
	class Model : public Object
	{
	private:
	protected:
		unsigned short _verticesCount;
		unsigned short _trianglesCount;
		unsigned short _materialsCount;
		BoundingBox _boundingBox;

		Model(const string& name)
			: Object(name)
		{
		}

	public:
		virtual ~Model()
		{
		}

		inline void SetVerticesCount(const unsigned short verticesCount) { _verticesCount = verticesCount; }
		inline unsigned short GetVerticesCount() const { return _verticesCount; }
		inline void SetTrianglesCount(const unsigned short trianglesCount) { _trianglesCount = trianglesCount; }
		inline unsigned short GetTrianglesCount() const { return _trianglesCount; }
		inline void SetMaterialsCount(const unsigned short materialsCount) { _materialsCount = materialsCount; }
		inline unsigned short GetMaterialsCount() const { return _materialsCount; }
		inline void SetBoundingBox(const BoundingBox& boundingBox) { _boundingBox = boundingBox; }
		inline BoundingBox& GetBoundingBox() { return _boundingBox; }

		virtual void Render() = 0;
	};
}