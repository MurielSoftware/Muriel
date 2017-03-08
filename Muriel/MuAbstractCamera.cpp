#include "stdafx.h"
#include "MuAbstractCamera.h"
#include "MuMouse.h"

namespace Muriel
{
	const Vec3 AbstractCamera::WORLD_XAXIS(1.0f, 0.0f, 0.0f);
	const Vec3 AbstractCamera::WORLD_YAXIS(0.0f, 1.0f, 0.0f);
	const Vec3 AbstractCamera::WORLD_ZAXIS(0.0f, 0.0f, 1.0f);

	AbstractCamera::AbstractCamera()
	{
		_fovx = 90.0f;
		_znear = 0.1f;
		_zfar = 1000.0f;
		_xAxis.Set(1.0f, 0.0f, 0.0f);
		_yAxis.Set(0.0f, 1.0f, 0.0f);
		_zAxis.Set(0.0f, 0.0f, 1.0f);
		_accumPitchDegrees = 0.0f;
		_orientation.Identity();
		_viewMatrix.Identity();
		_projMatrix.Identity();
	}

	AbstractCamera::~AbstractCamera()
	{

	}

	void AbstractCamera::LookAt(const Vec3 &target)
	{
		LookAt(_eye, target, _yAxis);
	}

	void AbstractCamera::LookAt(const Vec3 &eye, const Vec3 &target, const Vec3 &up)
	{
		_eye = eye;
		_target = target;

		_zAxis = eye - target;
		_zAxis.Normalize();

		_viewDir = Vec3::INVERT(_zAxis);

		_xAxis = Vec3::CROSS(up, _zAxis);
		_xAxis.Normalize();

		_yAxis = Vec3::CROSS(_zAxis, _xAxis);
		_yAxis.Normalize();
		_xAxis.Normalize();

		_viewMatrix[0] = _xAxis.x;
		_viewMatrix[1] = _xAxis.y;
		_viewMatrix[2] = _xAxis.z;
		_viewMatrix[3] = -Vec3::DOT(_xAxis, eye);

		_viewMatrix[4] = _yAxis.x;
		_viewMatrix[5] = _yAxis.y;
		_viewMatrix[6] = _yAxis.z;
		_viewMatrix[7] = -Vec3::DOT(_yAxis, eye);

		_viewMatrix[8] = _zAxis.x;
		_viewMatrix[9] = _zAxis.y;
		_viewMatrix[10] = _zAxis.z;
		_viewMatrix[11] = -Vec3::DOT(_zAxis, eye);

		//	_accumPitchDegrees = RADIANS_TO_DEGREES(asinf(_viewMatrix[6]));

		_orientation.FromMatrix(_viewMatrix);
	}

	void AbstractCamera::Move(float dx, float dy, float dz)
	{
		Vec3 eye = _eye;
		Vec3 forwards;

		forwards = Vec3::CROSS(WORLD_YAXIS, _xAxis);
		forwards.Normalize();

		eye += _xAxis * dx;
		eye += WORLD_YAXIS * dy;
		eye += forwards * dz;

		SetPosition(eye);
	}

	void AbstractCamera::Move(const Vec3 &direction, const Vec3 &amount)
	{
		_eye.x += direction.x * amount.x;
		_eye.y += direction.y * amount.y;
		_eye.z += direction.z * amount.z;
	}

	void AbstractCamera::Rotate(float headingDegrees, float pitchDegrees, float rollDegrees)
	{
		pitchDegrees = -pitchDegrees;
		headingDegrees = -headingDegrees;
		rollDegrees = -rollDegrees;

		DoRotate(headingDegrees, pitchDegrees, rollDegrees);
	}

	void AbstractCamera::Perspective(float fovx, float aspect, float znear, float zfar)
	{
		float e = 1.0f / tanf(DEGREES_TO_RADIANS(fovx) / 2.0f);
		float aspectInv = 1.0f / aspect;
		float fovy = 2.0f * atanf(aspectInv / e);
		float xScale = 1.0f / tanf(0.5f * fovy);
		float yScale = xScale / aspectInv;

		_projMatrix[0] = xScale;
		_projMatrix[1] = 0.0f;
		_projMatrix[2] = 0.0f;
		_projMatrix[3] = 0.0f;

		_projMatrix[4] = 0.0f;
		_projMatrix[5] = yScale;
		_projMatrix[6] = 0.0f;
		_projMatrix[7] = 0.0f;

		_projMatrix[8] = 0.0f;
		_projMatrix[9] = 0.0f;
		_projMatrix[10] = (zfar + znear) / (znear - zfar);
		_projMatrix[11] = -1.0f;

		_projMatrix[12] = 0.0f;
		_projMatrix[13] = 0.0f;
		_projMatrix[14] = (2.0f * zfar * znear) / (znear - zfar);
		_projMatrix[15] = 0.0f;

		_fovx = fovx;
		_aspectRatio = aspect;
		_znear = znear;
		_zfar = zfar;
	}

	void AbstractCamera::UpdateCamera()
	{
		Mouse* mouse = Mouse::GetInstance();
		float pitch = mouse->GetYDistanceFromWindowCenter() * 0.2f;
		float heading = -mouse->GetXDistanceFromWindowCenter() * 0.2f;

		Rotate(heading, pitch, 0.0f);

		_viewMatrix = _orientation.ToMatrix4();

		_xAxis.Set(_viewMatrix[0], _viewMatrix[4], _viewMatrix[8]);
		_yAxis.Set(_viewMatrix[1], _viewMatrix[5], _viewMatrix[9]);
		_zAxis.Set(_viewMatrix[2], _viewMatrix[6], _viewMatrix[10]);
		_viewDir = Vec3::INVERT(_zAxis);

		DoAdditionalEyeUpdateCamera();

		_viewMatrix[12] = -Vec3::DOT(_xAxis, _eye);
		_viewMatrix[13] = -Vec3::DOT(_yAxis, _eye);
		_viewMatrix[14] = -Vec3::DOT(_zAxis, _eye);

		_projViewMatrix = _projMatrix * _viewMatrix;
		//_normalMatrix = Mat3x3(_viewMatrix);
		//_normalMatrix = Mat3x3::INVERT(_normalMatrix);
		//_normalMatrix = _normalMatrix.Transpose();
		_frustum.CalculateFrustum(_projViewMatrix);
	}
}