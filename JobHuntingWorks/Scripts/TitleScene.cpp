
#include "TitleScene.h"

void TitleScene::LatestSceneType()
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

void TitleScene::Init()
{
	sceneType = SceneType::Update;
}

void TitleScene::Update()
{
	Message();
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		sceneType = SceneType::Finish;
	}
}

void TitleScene::Draw()
{
	
}

void TitleScene::Finish()
{
	sceneType = SceneType::Init;
	sceneKind = SceneKind::Game;
	Loading();	
}
