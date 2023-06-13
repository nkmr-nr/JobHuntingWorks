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
		MoveState,
	};
public:
	StateBase(EnemyState state_)
		:state(state_)
	{

	}
	~StateBase()
	{

	}
	virtual StateBase* Update(Enemy* enemy) = 0;			//XVˆ—
protected:
	EnemyState state;														//Enemy‚Ìó‘Ô
};

#endif//#define STATE_BASE_H_
