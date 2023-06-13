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
	static Move* Instance()									//Attack状態のインスタンス
	{
		static Move pInstance;
		return &pInstance;
	}
	StateBase* Update(Enemy* enemy)override;			//Enemyの状態を返す
};

#endif//#define MOVE_STATE_H_
