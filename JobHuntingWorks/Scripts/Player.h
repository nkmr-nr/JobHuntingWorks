//#pragma once
#ifndef PLAYER_H_
#define PLAYER_H_

#include<DxLib.h>
#include"Collider.h"
#include"Objects.h"
#include"PlayerAnimation.h"

#define DEBUG_COLLISION
//�f�o�b�O�p
#ifdef DEBUG_COLLISION
extern int g_BoxHandle;
#endif

class Player : public Object
{
public:
	Player(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_,int stageHandle_,int healthPoint_)
		:Object(pos_,rotateDegree_,scale_,modelHandle_,stageHandle_,healthPoint_)
		, isAttacking(false)
		, collider(VGet(200.0f, 30.0f, 30.0f), VGet(-100.0f, 10.0f, 0.0f))
		,playerAnim(PlayerAnimation::Instance(this))
	{
		CreateIdentityMatrix(&worldMatrix);
		CreateScalingMatrix(&matricesScale, 0.01f, 0.01f, 0.01f);
//�f�o�b�O�p
#if defined DEBUG_COLLISION
		CreateIdentityMatrix(&collisionBoxMatrix);
#endif
	}
	~Player()
	{

	}
	void Init()override;
	void Update()override;
	void UpdateMatrix();
	void Draw()override;
private:
	int isAttacking;						//�U�������ǂ���

	MATRIX worldMatrix;				//���[���h���W�̍s��
	MATRIX matricesScale;				//�g�k�p�s��

	OBBCollider collider;				//�R���C�_�[
	PlayerAnimation* playerAnim;	//�v���C���[�̃A�j���[�V����
#if defined DEBUG_COLLISION
	MATRIX collisionBoxMatrix;		// �f�o�b�O�p�̒����̕`��̂��߂̍s��
#endif
};

#endif//#define PLAYER_H_
