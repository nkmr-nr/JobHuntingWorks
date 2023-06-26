
#include "GameScene.h"
#include "SceneBase.h"

#include"ObjectsFactory.h"
#include"ObjectsManager.h"
#include"Objects.h"

#include"NonObjects.h"
#include"NonObjectsManager.h"
#include"NonObjectsFactory.h"

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
	Objects* playerInstance = ObjectsFactory::Instance()->CreatePlayer(VGet(0, 0, 0), VGet(0, 0, 0), VGet(0.4f, 0.4f, 0.4f), -1, -1, 10);
	Objects* enemyInstance = ObjectsFactory::Instance()->CreateEnemy(VGet(0, -40, 0), VGet(0, 0, 0), VGet(0.5f, 0.5f, 0.5f), -1, -1, 0, playerInstance);
	Objects* collisionInstance = ObjectsFactory::Instance()->CreateCollision(playerInstance, enemyInstance, nullptr, nullptr);

	ObjectsManager::Instance()->Entry(playerInstance);
	ObjectsManager::Instance()->Entry(enemyInstance);
	ObjectsManager::Instance()->Entry(collisionInstance);
	ObjectsManager::Instance()->Entry(ObjectsFactory::Instance()->CreateMap(VGet(0, 0, 0), VGet(0, 0, 0), VGet(1, 1, 1), -1));
	ObjectsManager::Instance()->Entry(ObjectsFactory::Instance()->CreateGoal(VGet(1000, 50, 1000), VGet(0, 0, 0), VGet(50, 50, 50), -1, -1, 0));

	ObjectsManager::Instance()->Init();

	NonObjectsManager::Instance()->Entry(NonObjectsFactory::Instance()->CreateCamera(playerInstance));
	NonObjectsManager::Instance()->Init();

	sceneType = SceneType::Update;
}

void GameScene::Update()
{
	ObjectsManager::Instance()->Update();
	NonObjectsManager::Instance()->Update();
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
