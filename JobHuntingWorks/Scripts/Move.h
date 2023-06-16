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
	static Move* Instance()									//Attack状態のインスタンス
	{
		static Move pInstance;
		return &pInstance;
	}
	StateBase* Update(Enemy* enemy)override;			//Enemyの状態を返す
private:
	VECTOR moveVec;
	int degree;
	bool isDecision;
};

#endif//#define MOVE_STATE_H_
