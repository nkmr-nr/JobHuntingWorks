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
	static Chase* Instance()					//Attack状態のインスタンス
	{
		static Chase pInstance;
		return &pInstance;
	}
	StateBase* Update(Enemy*enemy)override;
};

#endif//#define STATE_CHASE_H_
