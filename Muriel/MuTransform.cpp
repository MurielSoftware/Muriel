#include "stdafx.h"
#include "MuTransform.h"

namespace Muriel
{
	Transform::Transform()
	{
		_parent = NULL;
	}

	Transform::~Transform()
	{

	}

	const Vec3 Transform::GetScale() const
	{
		return Vec3(_scaleMatrix[0], _scaleMatrix[5], _scaleMatrix[10]);
	}

	const Vec3 Transform::GetRotationEuler() const
	{
		return _rotation.ToVector();
	}

	const Vec3 Transform::GetPosition() const
	{
		return Vec3(_scaleMatrix[12], _scaleMatrix[13], _scaleMatrix[14]);
	}

	const Mat4x4& Transform::GetWorldMatrix()
	{
		CalculateWorldMatrix();
		return _worldMatrix;
	}

	const Vec3 Transform::GetForward() const
	{
		return Vec3(_scaleMatrix[8], _scaleMatrix[9], _scaleMatrix[10]);
	}

	const Vec3 Transform::GetRight() const
	{
		return Vec3(_scaleMatrix[0], _scaleMatrix[1], _scaleMatrix[2]);
	}

	const Vec3 Transform::GetUp() const
	{
		return Vec3(_scaleMatrix[4], _scaleMatrix[5], _scaleMatrix[6]);
	}

	void Transform::SetScale(float x, float y, float z)
	{
		_scaleMatrix[0] = x;
		_scaleMatrix[5] = y;
		_scaleMatrix[10] = z;
	}

	void Transform::SetScale(const Vec3& scale)
	{
		SetScale(scale.x, scale.y, scale.z);
	}

	void Transform::SetRotationEuler(float x, float y, float z)
	{
		SetRotationEuler(Vec3(x, y, z));
	}

	void Transform::SetRotationEuler(const Vec3& eulerAngles)
	{
		_rotation.FromAxisAngle(eulerAngles);
	}

	void Transform::SetRotation(const Quat& rotation)
	{
		_rotation = rotation;
	}

	void Transform::SetPosition(float x, float y, float z)
	{
		_positionMatrix[12] = x;
		_positionMatrix[13] = y;
		_positionMatrix[14] = z;
	}

	void Transform::SetPosition(const Vec3& position)
	{
		SetPosition(position.x, position.y, position.z);
	}

	void Transform::SetParent(Transform* parent)
	{
		_parent = parent;
	}

	void Transform::Rotate(const Vec3& axis, const float angleInRadians)
	{
		_rotation = Quat::CREATE_FROM_AXIS_ANGLE(axis, angleInRadians) * _rotation;
	}

	void Transform::CalculateWorldMatrix()
	{
		_rotationMatrix = _rotation.ToMatrix4();
		_worldMatrix = _scaleMatrix;
		_worldMatrix = _worldMatrix * _rotationMatrix;
		_worldMatrix = _worldMatrix * _positionMatrix;

		if (_parent != NULL)
		{
			_worldMatrix = _parent->GetWorldMatrix() * _worldMatrix;
		}
	}
}