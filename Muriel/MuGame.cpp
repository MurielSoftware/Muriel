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
#include "MuBaseMaterial.h"
#include "MuTextureManager.h"
#include "MuMeshRenderer.h"
#include "MuDiffuseMaterial.h"
#include "MuDirectionalLight.h"
#include "MuModelManager.h"
#include "MuBumpMaterial.h"
#include "MuRenderEngine.h"
#include "MuRenderEngine2D.h"
#include "MuGameComponent.h"

namespace Muriel
{
	Game::Game()
	{
		Init();
	}

	Game::~Game()
	{
		for (GameObject* gameObject : _gameObjects)
		{
			delete gameObject;
		}
		_gameObjects.clear();

		delete _renderEngine;
		delete _renderEngine2D;

		Log::GetInstance()->Destroy();
	}

	void Game::Init()
	{
		GL::ClearColor(Color(0.0f, 0.0f, 0.0f));

		Keyboard::GetInstance()->Initialize();
		Mouse::GetInstance()->Initialize(true);

		_renderEngine = new RenderEngine();
		_renderEngine2D = new RenderEngine2D();

		Shader* shader = ShaderManager::GetInstance()->Load(SHADER_BASE_NAME, SHADER_BASE_PATH);
		Shader* bumpShader = ShaderManager::GetInstance()->Load(SHADER_BUMP_NAME, SHADER_BUMP_PATH);
		Shader* directionalLightShader = ShaderManager::GetInstance()->Load("directionallight", "data/shaders/directionallight");
		Texture* texture = TextureManager::GetInstance()->Load("box", "data/textures/box.jpg");
		Texture* textureStone = TextureManager::GetInstance()->Load("stone", "data/textures/stone.jpg");
		Texture* textureStoneNormal = TextureManager::GetInstance()->Load("stoneNormal", "data/textures/stone_normal.jpg");
		BumpMaterial* boxMaterial = new BumpMaterial(bumpShader, textureStone, textureStoneNormal);
		Model* model = ModelManager::GetInstance()->Load("scooter", "data/models/scooter.ms3d");
		_directionalLight = new DirectionalLight("light", *directionalLightShader, Color(1.0f, 1.0f, 1.0f), 0.7f);
		//Box* box = new Box("box");
		//box->SetRenderer(new MeshRenderer(box, boxMaterial));
		//box->GetTransform().SetPosition(0, 0, 0);
		GameObject* gameObject = new GameObject("scooter");
		gameObject->SetModel(model);
		gameObject->AddComponent(new MeshRenderer(gameObject, boxMaterial));
		AddGameObject(gameObject);

	}

	void Game::AddGameObject(GameObject* gameObject)
	{
		_gameObjects.push_back(gameObject);
		for (GameComponent* gameComponent : gameObject->GetComponents())
		{
			switch (gameComponent->GetGameComponentType())
			{
			case GameComponentType::RENDER:
				_renderEngine->RegisterRenderer(static_cast<Renderer*>(gameComponent));
				break;
			case GameComponentType::RENDER_2D:
				_renderEngine2D->RegisterRenderer(static_cast<Renderer*>(gameComponent));
				break;
			}
		}
	}

	void Game::ProccessFrame(Timer* timer)
	{
		Input(timer);
		Update(timer);
		Render(timer);
	}

	void Game::Input(Timer* timer)
	{
		Keyboard::GetInstance()->Update();
		Mouse::GetInstance()->Update();
	}

	void Game::Update(Timer* timer)
	{
		_renderEngine->Update(timer);
	}

	void Game::Render(Timer* timer)
	{
		GL::ClearBuffers(true, true, false);
	//	
	////	_directionalLight->GetShader().Activate();
	//	for (GameObject* gameObject : _gameObjects)
	//	{
	//		//_directionalLight->GetShader().UniformMat4x4("worldMatrix", false, gameObject->GetTransform().GetWorldMatrix());
	//		//_directionalLight->GetShader().UniformMat4x4("projectionViewMatrix", false, _camera->GetProjectionViewMatrix());
	//		//_directionalLight->GetShader().UniformMat4x4("modelViewMatrix", false, _camera->GetViewMatrix());
	//		//_directionalLight->GetShader().UniformMat3x3("normalMatrix", false, _camera->GetNormalMatrix());
	//		//_directionalLight->GetShader().Uniform3f("cameraPosition", _camera->GetPosition());	

	//		IRenderer* renderer = gameObject->GetRenderer();
	//		renderer->PreRender(_camera);
	//		renderer->Render();
	//		renderer->PostRender();
	//	}

	////	_directionalLight->GetShader().Deactivate();
		_renderEngine->Render(timer);
		_renderEngine2D->Render(timer);

		//glFlush();
		SwapBuffers(g_hDC);
	}
}