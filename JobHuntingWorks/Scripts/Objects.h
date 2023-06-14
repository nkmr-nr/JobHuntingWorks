//#pragma once
#ifndef OBJECTS_H_
#define OBJECTS_H_

#include<DxLib.h>

class Objects
{
public:
	Objects(VECTOR pos_,VECTOR rotateDegree_,VECTOR scale_,int modelHandle_,int stageHandle_,int healthPoint_)
		:isActive(true)
		,pos(pos_)
		, rotateDegree(rotateDegree_)
		,scale(scale_)
		,modelHandle(modelHandle_)
		,stageHandle(stageHandle_)
		,healthPoint(healthPoint_)
	{

	}
	virtual~Objects()
	{

	}
	virtual void Init() = 0;			//�I�u�W�F�N�g�̏�����
	virtual void Update() = 0;		//�I�u�W�F�N�g�̍X�V
	virtual void Draw() = 0;		//�I�u�W�F�N�g�̕`��
	VECTOR GetPos()				//�I�u�W�F�N�g�̃|�W�V�������
	{
		return pos;
	}
	VECTOR GetRadius()			//�I�u�W�F�N�g�̊p�x
	{
		return rotateDegree;
	}
	int GetModelHandle()			//�I�u�W�F�N�g�̃��f�����
	{
		return modelHandle;
	}
	bool IsActive()						//�I�u�W�F�N�g�̐����m�F
	{
		return isActive;
	}
	void OnCollisionStage();		//�I�u�W�F�N�g�ƃX�e�[�W�̓����蔻��
protected:
	bool isActive;						//�������Ă邩
	VECTOR pos;						//�|�W�V����
	VECTOR rotateDegree;		//�p�x
	VECTOR scale;					//�傫��
	int modelHandle;					//�摜�n���h��
	int stageHandle;					//�X�e�[�W�Ƃ̓����蔻��p
	int healthPoint;					//�̗�
};

#endif//#define OBJECTS_H_
