//#pragma once
#ifndef TITLE_SCENE_H_
#define TITLE_SCENE_H_

#include"SceneBase.h"
#include"GameScene.h"

class TitleScene : public SceneBase
{
private:
	TitleScene()
		:SceneBase(SceneKind::Title)
	{
	}
public:
	~TitleScene()
	{

	}
	static TitleScene* Instance()		//TitleSceneのインスタンス
	{
		static TitleScene pInstance;
		return &pInstance;
	}
	void LatestSceneType()override;	//適切な関数を呼ぶ
	void Init()override;					//初期化
	void Update()override;				//更新
	void Draw()override;				//描画
	void Finish()override;				//終了時実行関数
};

#endif//#define TITLE_SCENE_H_
