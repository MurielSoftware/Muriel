#pragma once

#include "MuModel.h"
#include "MuMS3DStructures.h"

namespace Muriel
{
	class MS3DModel : public Model
	{
	private:
		unsigned short _meshesCount;
		unsigned short _jointsCount;
		float _fps;
		float _curFrame;
		int _numFrame;
		MS3DVertex* _vertices;
		MS3DTriangle* _triangles;
		MS3DMesh* _meshes;
		MS3DMaterial* _materials;
		MS3DJoint* _joints;
	public:
		MS3DModel(const string& name);
		~MS3DModel();

		inline void SetMeshesCount(const unsigned short meshesCount) { _meshesCount = meshesCount; }
		inline unsigned short GetMeshesCount() const { return _meshesCount; }
		inline void SetJointsCount(const unsigned short jointsCount) { _jointsCount = jointsCount; }
		inline unsigned short GetJointsCount() { return _jointsCount; }
		inline void SetFps(float fps) { _fps = fps; }
		inline float GetFps() { return _fps; }
		inline void SetCurFrame(float curFrame) { _curFrame = curFrame; }
		inline float GetCurFrame() { return _curFrame; }
		inline void SetNumFrame(int numFrame) { _numFrame = numFrame; }
		inline int GetNumFrame() { return _numFrame; }
		inline void SetVertices(MS3DVertex* vertices) { _vertices = vertices; }
		inline MS3DVertex* GetVertices() { return _vertices; }
		inline void SetTriangles(MS3DTriangle* triangles) { _triangles = triangles; }
		inline MS3DTriangle* GetTris() { return _triangles; }
		inline void SetMeshes(MS3DMesh* meshes) { _meshes = meshes; }
		inline MS3DMesh* GetMeshes() { return _meshes; }
		inline void SetMaterials(MS3DMaterial* materials) { _materials = materials; }
		inline MS3DMaterial* GetMaterials() { return _materials; }
		inline void SetJoints(MS3DJoint* joints) { _joints = joints; }
		inline MS3DJoint* GetJoints() { return _joints; }

		void Setup();
		void CreateBuffers();
		void Animate(float dt);
		void Render();
	};
}