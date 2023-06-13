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
	static Attack* Instance()					//Attack状態のインスタンス
	{
		static Attack pInstance;
		return &pInstance;
	}
	void Update(Enemy*enemy)override;						//更新処理
	EnemyState GetEnemyState()override	//Attack状態を返す関数
	{
		return EnemyState::AttackState;
	}
};

#endif//#define STATE_ATTACK_H_
