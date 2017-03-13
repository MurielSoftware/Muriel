#include "stdafx.h"
#include "MuObject.h"
#include "MuGameObject.h"
//#include "MuVertexBuffer.h"
//#include "MuIndexBuffer.h"
//#include "MuGL.h"
//#include "MuMaterial.h"
//#include "MuShader.h"
//#include "MuAbstractCamera.h"

namespace Muriel
{
	GameObject::GameObject(const string& name)
		: Object(name)
	{
	}

	GameObject::~GameObject()
	{
	}

	Transform& GameObject::GetTransform()
	{ 
		return _transform; 
	}

	void GameObject::AddComponent(GameComponent* component)
	{
		_components.push_back(component);
	}
}