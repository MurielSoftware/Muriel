#include "stdafx.h"
#include "MuGame.h"
#include "MuSceneManager.h"
#include "MuKeyboard.h"
#include "MuMouse.h"
#include "MuFirstPersonCamera.h"
#include "MuOrbitCamera.h"
#include "MuTimer.h"
#include "MuBox.h"
#include "MuShaderManager.h"
#include "MuLog.h"
#include "MuMaterial.h"
#include "MuTextureManager.h"
#include "MuMeshRenderer.h"
#include "MuDiffuseMaterial.h"

namespace Muriel
{
	Game::Game()
	{
		Init();
	}

	Game::~Game()
	{
		delete _camera;
		for (GameObject* gameObject : _gameObjects)
		{
			delete gameObject;
		}
		_gameObjects.clear();
		Log::GetInstance()->Destroy();
	}

	void Game::Init()
	{
		Keyboard::GetInstance()->Init();
		Mouse::GetInstance()->Init(true);

		CreateCamera();

		Shader* shader = ShaderManager::GetInstance()->Load("base", "data/shaders/base");
		Texture* texture = TextureManager::GetInstance()->Load("box", "data/textures/box.jpg");
		DiffuseMaterial* boxMaterial = new DiffuseMaterial(shader, texture);

		Box* box = new Box("box");
		//box->SetMaterial(boxMaterial);
		box->SetRenderer(new MeshRenderer(box, boxMaterial));
		box->GetTransform().SetPosition(0, 0, 0);
		_gameObjects.push_back(box);

	}

	void Game::AddGameObject(GameObject* gameObject)
	{
		_gameObjects.push_back(gameObject);
	}

	void Game::ProccessFrame(Timer* timer)
	{
		Input(timer);
		Update(timer);
		Render(timer);
	}

	void Game::CreateCamera()
	{
		_camera = new OrbitCamera();
		_camera->Perspective(90.0f, 1.3f, 0.1f, 1000.0f);
	}

	void Game::Input(Timer* timer)
	{
		Keyboard::GetInstance()->Update();
		Mouse::GetInstance()->Update();
	}

	void Game::Update(Timer* timer)
	{
		_camera->UpdateCamera();		
	}

	void Game::Render(Timer* timer)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (GameObject* gameObject : _gameObjects)
		{
			IRenderer* renderer = gameObject->GetRenderer();
			renderer->PreRender(_camera);
			renderer->Render();
			renderer->PostRender();
		}
		glFlush();
		SwapBuffers(g_hDC);
	}
}