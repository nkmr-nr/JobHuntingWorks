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
		,counter(0)
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
	StateBase* Update(Enemy* enemy)override;		//Enemy�̏�Ԃ�Ԃ�
private:
	int counter;
};

#endif//#define MOVE_STATE_H_
