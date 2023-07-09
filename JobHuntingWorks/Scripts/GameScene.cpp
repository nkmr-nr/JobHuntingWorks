
#include "GameScene.h"
#include "SceneBase.h"

#include"ManagerAdministrator.h"

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
	ManagerAdministrator::Instance()->Init();

	sceneType = SceneType::Update;
}

void GameScene::Update()
{
	ManagerAdministrator::Instance()->Update();
	if (ManagerAdministrator::Instance()->IsDead() == true)
	{
		sceneType = SceneType::Finish;
	}
}

void GameScene::Draw()
{
	ManagerAdministrator::Instance()->Draw();
}

void GameScene::Finish()
{
	ManagerAdministrator::Instance()->Finish();
	Loading();
	sceneKind = SceneKind::End;
	sceneType = SceneType::Init;
}
