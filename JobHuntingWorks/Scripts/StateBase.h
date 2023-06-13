//#pragma once
#ifndef STATE_BASE_H_
#define STATE_BASE_H_

class Enemy;

class StateBase
{
public:
	enum class EnemyState
	{
		WaitState,
		AttackState,
		ChaseState,
	};
public:
	StateBase(EnemyState state_)
		:state(state_)
	{

	}
	~StateBase()
	{

	}
	virtual void Update(Enemy*enemy) = 0;							//更新処理
	virtual EnemyState GetEnemyState() = 0;	//Enemyの状態取得関数
protected:
	EnemyState state;										//Enemyの状態
};

#endif//#define STATE_BASE_H_
