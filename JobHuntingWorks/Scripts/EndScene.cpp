#include "EndScene.h"

void EndScene::LatestSceneType()
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

void EndScene::Init()
{
	sceneType = SceneType::Update;
}

void EndScene::Update()
{
	sceneType = SceneType::Finish;
}

void EndScene::Draw()
{
}

void EndScene::Finish()
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		DxLib_End();
	}
}
