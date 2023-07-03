
#include"ObjectsFactory.h"
#include"ObjectsManager.h"
#include"Objects.h"

#include "SceneBase.h"
#include "SceneManager.h"

void SceneManager::LatestState()
{
	sceneKind = type->GetSceneKind();
	switch (sceneKind)
	{
	case SceneBase::SceneKind::Title:
		type = TitleScene::Instance();
		break;
	case SceneBase::SceneKind::Game:
		type = GameScene::Instance();
		break;
	case SceneBase::SceneKind::End:
		type = EndScene::Instance();
		break;
	default:
		break;
	}
}


void SceneManager::GameLoop()
{
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		LatestState();
		
		ClearDrawScreen();
		
		type->LatestSceneType();

		ScreenFlip();
	}
	type->Finish();
}
