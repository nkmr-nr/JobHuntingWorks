//#pragma once
#ifndef ENEMMY_H_
#define ENEMMY_H_

#include"Objects.h"
#include"Wait.h"
#include"StateBase.h"
#include"EnemyAnimation.h"

class Enemy : public Objects
{
public:
	Enemy(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_, int stageHandle_, int healthPoint_)
		:Objects(pos_, rotateDegree_,scale_,modelHandle_,stageHandle_,healthPoint_)
		,state(Wait::Instance())
		,counter(0)
		,enemyAnim(EnemyAnimation::Instance(this))
	{

	}
	~Enemy()
	{

	}
	void Init()override;					//������
	void Update()override;				//�X�V
	void Draw()override;				//�`��
private:
	StateBase* state;						//Enemy�̏��
	int counter;								//wait��counter
	EnemyAnimation* enemyAnim;	//Enemy�̃A�j���[�V����
};

#endif//#define ENEMMY_H_
