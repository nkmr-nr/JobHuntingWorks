//#pragma once
#ifndef STATE_CHASE_H_
#define STATE_CHASE_H_

#include"StateBase.h"

class Chase : public StateBase
{
private:
	Chase()
		:StateBase(EnemyState::ChaseState)
	{

	}
public:
	~Chase()
	{

	}
	static Chase* Instance()					//Attack��Ԃ̃C���X�^���X
	{
		static Chase pInstance;
		return &pInstance;
	}
	void Update(Enemy*enemy)override;
	EnemyState GetEnemyState()override//Chase��Ԃ�Ԃ��֐�
	{
		return EnemyState::ChaseState;
	}
};

#endif//#define STATE_CHASE_H_
