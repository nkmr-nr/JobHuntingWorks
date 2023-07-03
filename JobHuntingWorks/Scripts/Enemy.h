//#pragma once
#ifndef ENEMMY_H_
#define ENEMMY_H_

#include"Objects.h"
#include"Wait.h"
#include"StateBase.h"
#include"EnemyAnimation.h"
#include<math.h>
#include"Collider.h"

class Player;

class Enemy : public Object
{
public:
	Enemy(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_, int stageHandle_, int healthPoint_, Object*player_)
		:Object(pos_, rotateDegree_,scale_,modelHandle_,stageHandle_,healthPoint_)
		,state(Wait::Instance())
		,counter(0)
		,enemyAnim(EnemyAnimation::Instance(this))
		,player(player_)
		,moveVec(VGet(0,0,0))
		,rectCollider(&pos,&scale)
	{

	}
	~Enemy()
	{

	}
	void Init()override;										//������
	void Update()override;									//�X�V
	void Draw()override;									//�`��
	bool IsFound();											//���G�͈�
	int GetCounter()											//�J�E���g�𑝂₷
	{
		counter++;
		return counter;
	}
	void SetMoveVector(VECTOR vec)					//�v�f�̒l����
	{
		moveVec = vec;
	}
	void Move()												//���肵t�x�N�g���ɐi��
	{
		float length = sqrtf((moveVec.x * moveVec.x) + (moveVec.z * moveVec.z));
		pos = VAdd(pos, moveVec);
	}
	void GetAngle(float rotateDegree_y)				//��]�p�x
	{
		rotateDegree.y = rotateDegree_y;
	}
	VECTOR GetTargetDirectionZX();					//�G�ʒu�Z�o�p�֐�
	VECTOR GetRotateDegree()							//��]�p�x�擾�p�֐�
	{
		return rotateDegree;
	}

	RectCollider rectCollider;
private:
	StateBase* state;											//Enemy�̏��
	int counter;													//wait��counter
	EnemyAnimation* enemyAnim;						//Enemy�̃A�j���[�V����
	Object* player;											//���G�p
	VECTOR moveVec;										//�ړ��x�N�g��
};

#endif//#define ENEMMY_H_
