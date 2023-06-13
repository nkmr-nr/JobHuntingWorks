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
	static EndScene* Instance()		//EndScene�̃C���X�^���X
	{
		static EndScene pInstance;
		return &pInstance;
	}
	void LatestSceneType()override;	//�K�؂Ȋ֐����Ă�
	void Init()override;					//������
	void Update()override;				//�X�V
	void Draw()override;				//�`��
	void Finish()override;				//�I�������s�֐�
};

#endif//#define END_SCENE_H_
