#pragma once

#include "stdafx.h"
#include "MuObject.h"
#include "MuTransform.h"

namespace Muriel
{
	class MURIEL_API GameObject : public Object
	{
	private:
		Transform _transform;
		//Material* _material;
	protected:
		IRenderer* _renderer;
		VertexBuffer* _vertexBuffer;
		IndexBuffer* _indexBuffer;
	public:
		GameObject(const string& name);
		virtual ~GameObject();

		inline void SetRenderer(IRenderer* renderer) { _renderer = renderer; }
		inline IRenderer* GetRenderer() { return _renderer; }
		inline VertexBuffer* GetVertexBuffer() { return _vertexBuffer; }
		inline IndexBuffer* GetIndexBuffer() { return _indexBuffer; }

		//inline void SetMaterial(Material* material) { _material = material; }

		virtual Transform& GetTransform();
		//virtual void PreRender(AbstractCamera* camera);
		//virtual void Render();
	};
}