#include "stdafx.h"
#include "MuOrbitCamera.h"

namespace Muriel
{
	void OrbitCamera::DoRotate(float headingDegrees, float pitchDegrees, float rollDegrees)
	{
		Quat rot;
		if (headingDegrees != 0.0f)
		{
			rot.FromAxisAngle(WORLD_YAXIS, headingDegrees);
			_orientation = _orientation * rot;	
		}

		if (pitchDegrees != 0.0f)
		{
			rot.FromAxisAngle(WORLD_XAXIS, pitchDegrees);
			_orientation = rot * _orientation;
		}
	}

	void OrbitCamera::DoAdditionalEyeUpdateCamera()
	{
		_eye = _target + _zAxis * 10.0f;
	}
}