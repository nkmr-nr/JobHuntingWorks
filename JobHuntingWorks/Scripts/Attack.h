//#pragma once
#ifndef STATE_ATTACK_H_
#define STATE_ATTACK_H_

#include"StateBase.h"

class Attack : public StateBase
{
private:
	Attack()
		:StateBase(EnemyState::AttackState)
	{

	}
public:
	~Attack()
	{

	}
	static Attack* Instance()									//Attack状態のインスタンス
	{
		static Attack pInstance;
		return &pInstance;
	}
	StateBase* Update(Enemy*enemy)override;			//更新処理
};

#endif//#define STATE_ATTACK_H_
