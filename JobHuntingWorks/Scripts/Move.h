//#pragma once
#ifndef MOVE_STATE_H_
#define MOVE_STATE_H_

#include"StateBase.h"

class Move : public StateBase
{
private:
	Move()
		:StateBase(EnemyState::AttackState)
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
};

#endif//#define MOVE_STATE_H_
