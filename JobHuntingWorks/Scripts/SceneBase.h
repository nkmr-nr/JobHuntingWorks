//#pragma once
#ifndef SCENE_BASE_H_
#define SCENE_BASE_H_

#include <DxLib.h>
#include <string>

class SceneBase
{
public:
	enum class SceneKind
	{
		Title,
		Game,
		End,
	};
	enum class SceneType
	{
		Init,
		Update,
		Finish,
	};
public:
	SceneBase(SceneKind sceneKind_ )
		: sceneType(SceneType::Init)
		,sceneKind(sceneKind_)
	{
	}
	virtual~SceneBase()
	{

	}
	virtual void LatestSceneType() = 0;		//シーンの状態
	virtual void Init()= 0;						//初期化
	virtual void Update() = 0;					//更新
	virtual void Draw() = 0;					//描画
	virtual void Finish() = 0;					//終わるときにデリーとする時用
	SceneKind GetSceneKind()				//シーンの種類を返す
	{
		return sceneKind;
	}
	virtual void Loading();						//ロード画面
	virtual void Message();						//OOボタンを押してくださいのメッセージ
protected:
	SceneKind sceneKind;						//シーンの種類
	SceneType sceneType;						//シーンの状態
};

#endif//#define SCENE_BASE_H_
