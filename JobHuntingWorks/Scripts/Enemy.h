//#pragma once
#ifndef ENEMMY_H_
#define ENEMMY_H_

#include"Objects.h"
#include"Wait.h"
#include"StateBase.h"
#include"EnemyAnimation.h"
#include<math.h>

class Player;

class Enemy : public Objects
{
public:
	Enemy(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_, int stageHandle_, int healthPoint_,Objects*player_)
		:Objects(pos_, rotateDegree_,scale_,modelHandle_,stageHandle_,healthPoint_)
		,state(Wait::Instance())
		,counter(0)
		,enemyAnim(EnemyAnimation::Instance(this))
		,player(player_)
		,moveVec(VGet(0,0,0))
	{

	}
	~Enemy()
	{

	}
	void Init()override;						//������
	void Update()override;					//�X�V
	void Draw()override;					//�`��
	bool IsFound();	//���G�͈�
	int GetCounter()
	{
		counter++;
		return counter;
	}
	void MoveVec(VECTOR  moveVec_)
	{
		float length = sqrtf((moveVec_.x * moveVec_.x) + (moveVec_.z * moveVec_.z));
		pos = VAdd(pos, moveVec_);
	}
	VECTOR GetTargetDerectionXZ();
	void SetMoveVec(VECTOR derection)
	{
		moveVec = derection;
	}
	float GetRotateDegree_Y(float rotateDegree_Y)
	{
		return rotateDegree.y = rotateDegree_Y;
	}
private:
	StateBase* state;							//Enemy�̏��
	int counter;									//wait��counter
	EnemyAnimation* enemyAnim;		//Enemy�̃A�j���[�V����
	Objects* player;							//���G�p
	VECTOR moveVec;						//�ړ��x�N�g��
};

#endif//#define ENEMMY_H_
