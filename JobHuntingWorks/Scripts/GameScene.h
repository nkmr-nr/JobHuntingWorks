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
	static GameScene* Instance()		//GameScene�̃C���X�^���X
	{
		static GameScene pInstance;
		return &pInstance;
	}
	void LatestSceneType()override;	//�K�؂Ȋ֐����Ă�
	void Init()override;					//������
	void Update()override;				//�X�V
	void Draw()override;				//�`��
	void Finish()override;				//�I�������s�֐�
private:
};

#endif//#define GAME_SCENE_H_
