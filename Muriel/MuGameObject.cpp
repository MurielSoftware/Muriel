#include "stdafx.h"
#include "MuObject.h"
#include "MuGameObject.h"
#include "MuBoundingBox.h"
#include "MuModel.h"

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

	const BoundingBox& GameObject::GetTransformedBoundingBox()
	{
		const Vec3& thisPosition = _transform.GetPosition();
		Vec3 thisScale = _transform.GetScale();
		_transformedBoundingBox.SetCenter(thisPosition + Vec3::COMPONENT_PRODUCT(_model->GetBoundingBox().GetCenter(), thisScale));
		_transformedBoundingBox.SetHalfSize(Vec3::COMPONENT_PRODUCT(_model->GetBoundingBox().GetHalfSize(), thisScale));
		return _transformedBoundingBox;
	}
}