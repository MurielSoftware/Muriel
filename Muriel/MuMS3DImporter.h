#pragma once

#include "stdafx.h"

namespace Muriel
{
	class MS3DImporter
	{
	private:
		void LoadHeader(MS3DModel* model, ifstream& file);
		void Loadvertices(MS3DModel* model, ifstream& file);
		void LoadTriangles(MS3DModel* model, ifstream& file);
		void LoadMeshes(MS3DModel* model, ifstream& file);
		void LoadMaterials(MS3DModel* model, ifstream& file);
		void LoadAnimationInfo(MS3DModel* model, ifstream& file);
		void LoadJoints(MS3DModel* model, ifstream& file);
	public:
		Model* Import(const string& name, const string& path);
	};
}