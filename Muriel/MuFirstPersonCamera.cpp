#include "stdafx.h"
#include "MuFirstPersonCamera.h"

namespace Muriel
{
	void FirstPersonCamera::DoRotate(float headingDegrees, float pitchDegrees, float rollDegrees)
	{
		_accumPitchDegrees += pitchDegrees;

		if (_accumPitchDegrees > 90.0f)
		{
			pitchDegrees = 90.0f - (_accumPitchDegrees - pitchDegrees);
			_accumPitchDegrees = 90.0f;
		}

		if (_accumPitchDegrees < -90.0f)
		{
			pitchDegrees = -90.0f - (_accumPitchDegrees - pitchDegrees);
			_accumPitchDegrees = -90.0f;
		}

		Quat rot;

		if (headingDegrees != 0.0f)
		{
			rot.FromAxisAngle(WORLD_YAXIS, headingDegrees);
			_orientation = rot * _orientation;
		}

		if (pitchDegrees != 0.0f)
		{
			rot.FromAxisAngle(WORLD_XAXIS, pitchDegrees);
			_orientation = _orientation * rot;
		}
	}

	void FirstPersonCamera::DoAdditionalEyeUpdateCamera()
	{

	}
}