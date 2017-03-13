#pragma once

#include "stdafx.h"
#include "Quat.h"
#include "Vec3.h"
//#include "VertexBufferObject.h"

using namespace Glml;

namespace Muriel
{
#pragma pack(push)
#pragma pack(1)
	struct MS3DHeader
	{
		char id[10];
		int version;
	};

	struct MS3DVertex
	{
		unsigned char flags;
		Vec3 vert;
		char bone;
		unsigned char unused;
	};

	struct MS3DTriangle
	{
		unsigned short flags;
		unsigned short vertIndices[3];
		Vec3 normals[3];
		float texCoords[2][3];
		unsigned char smoothing;
		unsigned char group;
	};

	struct MS3DMesh
	{
		unsigned char flags;
		char name[32];
		unsigned short numTris;
		unsigned short* indices;
		char material;

	//	VertexBuffer* vertexBuffer;
		IndexBuffer* indexBuffer;
	};

	struct MS3DMaterial
	{
		char name[32];
		float ambient[4];
		float diffuse[4];
		float specular[4];
		float emissive[4];
		float shininess;
		float transparency;
		char mode;
		char textureName[128];
		char alpha[128];
	};

	struct MS3DKeyFrameTranslate
	{
		float time;
		Vec3 param;
	};

	struct MS3DKeyFrameRotate
	{
		float time;
		Quat param;
	};

	struct MS3DJoint
	{
		unsigned char flags;
		char name[32];
		char parent[32];
		Vec3 rotation;
		Vec3 position;
		MS3DKeyFrameRotate *rotateKeyFrames;
		MS3DKeyFrameTranslate *translateKeyFrames;
		unsigned short rotateKeyFramesCount;
		unsigned short translateKeyFramesCount;

		short parentIndex;

		Quat localQuaternion;
		Quat absoluteQuaternion;
		Quat finalQuaternion;

		Vec3 localVector;
		Vec3 absoluteVector;
		Vec3 finalVector;
	};
#pragma pack(pop)
}