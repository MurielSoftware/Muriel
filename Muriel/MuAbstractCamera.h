#pragma once

#include "Mat4x4.h"
#include "Vec3.h"
#include "Quat.h"
#include "MuFrustum.h"

using namespace Glml;

namespace Muriel
{
	class AbstractCamera
	{
	private:
		float _fovx;
		float _znear;
		float _zfar;
		float _aspectRatio;
	protected:
		float _accumPitchDegrees;
		Vec3 _xAxis;
		Vec3 _yAxis;
		Vec3 _zAxis;
		Vec3 _viewDir;
		Vec3 _eye;
		Vec3 _target;
		Quat _orientation;
		Mat4x4 _viewMatrix;
		Mat4x4 _projMatrix;
		Mat4x4 _projViewMatrix;
		Frustum _frustum;

		virtual void DoRotate(float headingDegrees, float pitchDegrees, float rollDegrees) = 0;
		virtual void DoAdditionalEyeUpdateCamera() = 0;
	public:
		static const Vec3 WORLD_XAXIS;
		static const Vec3 WORLD_YAXIS;
		static const Vec3 WORLD_ZAXIS;

		AbstractCamera();
		virtual ~AbstractCamera();

		inline void SetPosition(const Vec3 &position) { _eye = position; }
		inline Mat4x4 GetViewMatrix() const { return _viewMatrix; }
		inline Mat4x4 GetProjectionMatrix() const { return _projMatrix; }
		inline Mat4x4 GetProjectionViewMatrix() const { return _projViewMatrix; }

		void LookAt(const Vec3 &target);
		void LookAt(const Vec3 &eye, const Vec3 &target, const Vec3 &up);
		void Move(float dx, float dy, float dz);
		void Move(const Vec3 &direction, const Vec3 &amount);
		void Rotate(float headingDegrees, float pitchDegrees, float rollDegrees);
		void Perspective(float fovx, float aspect, float znear, float zfar);
		void UpdateCamera();
	};
}