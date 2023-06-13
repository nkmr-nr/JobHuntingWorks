
#include "GameScene.h"
#include "SceneBase.h"

#include"ObjectsFactory.h"
#include"ObjectsManager.h"
#include"Objects.h"

#include"Camera.h"

void GameScene::LatestSceneType()
{
	switch (sceneType)
	{
	case SceneType::Init:
		Init();
		break;
	case SceneType::Update:
		Update();
		Draw();
		break;
	case SceneType::Finish:
		Finish();
		break;
	default:
		break;
	}
}

void GameScene::Init()
{
	Objects* playerInstance = ObjectsFactory::Instance()->CreatePlayer(VGet(0, 0, 0), VGet(0, 0, 0), VGet(1, 1, 1), -1, -1, 10);
	ObjectsManager::Instance()->Entry(playerInstance);
	ObjectsManager::Instance()->Init();

	sceneType = SceneType::Update;
}

void GameScene::Update()
{
	ObjectsManager::Instance()->Update();
	ObjectsManager::Instance()->DeleteOnes();
}

void GameScene::Draw()
{
	ObjectsManager::Instance()->Draw();
}

void GameScene::Finish()
{
	ObjectsManager::Instance()->DeleteAll();
	Loading();
}
