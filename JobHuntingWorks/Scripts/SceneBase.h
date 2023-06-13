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
	virtual void LatestSceneType() = 0;		//�V�[���̏��
	virtual void Init()= 0;						//������
	virtual void Update() = 0;					//�X�V
	virtual void Draw() = 0;					//�`��
	virtual void Finish() = 0;					//�I���Ƃ��Ƀf���[�Ƃ��鎞�p
	SceneKind GetSceneKind()				//�V�[���̎�ނ�Ԃ�
	{
		return sceneKind;
	}
	virtual void Loading();						//���[�h���
	virtual void Message();						//OO�{�^���������Ă��������̃��b�Z�[�W
protected:
	SceneKind sceneKind;						//�V�[���̎��
	SceneType sceneType;						//�V�[���̏��
};

#endif//#define SCENE_BASE_H_
