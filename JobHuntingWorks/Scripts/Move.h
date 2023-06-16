//#pragma once
#ifndef MOVE_STATE_H_
#define MOVE_STATE_H_

#include"StateBase.h"
#include<DxLib.h>

class Move : public StateBase
{
private:
	Move()
		:StateBase(EnemyState::AttackState)
		, moveVec(VGet(0,0,0))
		,degree(0)
		,isDecision(false)
	{

	}
public:
	~Move()
	{

	}
	static Move* Instance()									//Attack��Ԃ̃C���X�^���X
	{
		static Move pInstance;
		return &pInstance;
	}
	StateBase* Update(Enemy* enemy)override;			//Enemy�̏�Ԃ�Ԃ�
private:
	VECTOR moveVec;
	int degree;
	bool isDecision;
};

#endif//#define MOVE_STATE_H_
