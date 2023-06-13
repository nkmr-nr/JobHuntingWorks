//#pragma once
#ifndef GAME_SCENE_H_
#define GAME_SCENE_H_

#include"SceneBase.h"
#include "EndScene.h"
#include <list>

class GameScene : public SceneBase
{
private:
	GameScene()
		:SceneBase(SceneKind::Game)
	{

	}
public:
	~GameScene()
	{

	}
	static GameScene* Instance()		//GameSceneのインスタンス
	{
		static GameScene pInstance;
		return &pInstance;
	}
	void LatestSceneType()override;	//適切な関数を呼ぶ
	void Init()override;					//初期化
	void Update()override;				//更新
	void Draw()override;				//描画
	void Finish()override;				//終了時実行関数
private:
};

#endif//#define GAME_SCENE_H_
