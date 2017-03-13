#pragma once

#include "stdafx.h"
#include "MuObject.h"
#include "MuTransform.h"

#include <vector>

namespace Muriel
{
	class MURIEL_API GameObject : public Object
	{
	private:
		Transform _transform;
	protected:
		IRenderer* _renderer;
		Model* _model;
		vector<GameComponent*> _components;
	public:
		GameObject(const string& name);
		virtual ~GameObject();

		inline void SetRenderer(IRenderer* renderer) { _renderer = renderer; }
		inline void SetModel(Model* model) { _model = model; }
		inline IRenderer* GetRenderer() { return _renderer; }
		inline Model* GetModel() { return _model; }
		inline vector<GameComponent*>& GetComponents() { return _components; }
		virtual Transform& GetTransform();
		virtual void AddComponent(GameComponent* component);
	};
}