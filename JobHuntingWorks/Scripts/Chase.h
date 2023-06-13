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
	void Update(Enemy*enemy)override;
	EnemyState GetEnemyState()override//Chase状態を返す関数
	{
		return EnemyState::ChaseState;
	}
};

#endif//#define STATE_CHASE_H_
