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
	static TitleScene* Instance()		//TitleScene�̃C���X�^���X
	{
		static TitleScene pInstance;
		return &pInstance;
	}
	void LatestSceneType()override;	//�K�؂Ȋ֐����Ă�
	void Init()override;					//������
	void Update()override;				//�X�V
	void Draw()override;				//�`��
	void Finish()override;				//�I�������s�֐�
};

#endif//#define TITLE_SCENE_H_
