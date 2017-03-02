#pragma once

#include "Mat4x4.h"
#include "Vec3.h"
#include "Quat.h"

using namespace Glml;

namespace Muriel
{
	class Transform
	{
	private:
		Mat4x4 _scaleMatrix;
		Mat4x4 _positionMatrix;
		Mat4x4 _rotationMatrix;
		Mat4x4 _worldMatrix;
		Quat _rotation;
		Vec3 _positionVector;
		Vec3 _scaleVector;
		Transform* _parent;
		Vec3 _up;
		Vec3 _right;
		Vec3 _forward;
		bool _didChange;

		void CalculateWorldMatrix();
	public:
		Transform();
		virtual ~Transform();

		const Vec3& GetScale();
		const Vec3 GetRotationEuler()const;
		const Vec3& GetPosition();
		const Mat4x4& GetWorldMatrix();
		const Vec3& GetForward();
		const Vec3& GetRight();
		const Vec3& GetUp();
		void SetScale(float x, float y, float z);
		void SetScale(const Vec3& scale);
		void SetRotationEuler(float x, float y, float z);
		void SetRotationEuler(const Vec3& eulerAngles);
		void SetRotation(const Quat& rotation);
		void SetPosition(float x, float y, float z);
		void SetPosition(const Vec3& position);
		void SetParent(Transform* parent);
		void Rotate(const Vec3& axis, const float angleInRadians);
	};
}