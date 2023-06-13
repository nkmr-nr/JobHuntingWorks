//#pragma once
#ifndef SCENE_FACTORY_H_
#define SCENE_FACTORY_H_

#include"SceneBase.h"
#include "TitleScene.h"
#include"GameScene.h"
#include"EndScene.h"

class SceneManager
{
private:
	SceneManager()
		:sceneKind(SceneBase::SceneKind::Title)
		,type(TitleScene::Instance())
	{
		sceneKind = SceneBase::SceneKind::Game;
	}
public:
	~SceneManager()
	{

	}
public:
	static SceneManager* Instance()		//SceneManagerのインスタンス
	{
		static SceneManager pInstance;
		return &pInstance;
	}
	SceneBase* LatestState();				//シーンの種類
	void GameLoop();						//ゲームループ
private:
	SceneBase::SceneKind sceneKind;	//シーンの種類
	SceneBase* type;							//シーンの状態
};

#endif//#define SCENE_FACTORY_H_
