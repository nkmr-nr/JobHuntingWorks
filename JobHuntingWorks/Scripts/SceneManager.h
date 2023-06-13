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
	static SceneManager* Instance()		//SceneManager�̃C���X�^���X
	{
		static SceneManager pInstance;
		return &pInstance;
	}
	SceneBase* LatestState();				//�V�[���̎��
	void GameLoop();						//�Q�[�����[�v
private:
	SceneBase::SceneKind sceneKind;	//�V�[���̎��
	SceneBase* type;							//�V�[���̏��
};

#endif//#define SCENE_FACTORY_H_
