//#pragma once
#ifndef END_SCENE_H_
#define END_SCENE_H_

#include"SceneBase.h"
#include"TitleScene.h"

class EndScene : public SceneBase
{
private:
	EndScene()
		:SceneBase(SceneKind::End)
	{

	}
public:
	~EndScene()
	{

	}
	static EndScene* Instance()		//EndSceneのインスタンス
	{
		static EndScene pInstance;
		return &pInstance;
	}
	void LatestSceneType()override;	//適切な関数を呼ぶ
	void Init()override;					//初期化
	void Update()override;				//更新
	void Draw()override;				//描画
	void Finish()override;				//終了時実行関数
};

#endif//#define END_SCENE_H_
