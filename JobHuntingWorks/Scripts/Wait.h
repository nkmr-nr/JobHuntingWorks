//#pragma once
#ifndef STATE_WAIT_H_
#define STATE_WAIT_H_

#include"StateBase.h"

class Wait : public StateBase
{
private:
	Wait()
		:StateBase(EnemyState::WaitState)
		,counter(0)
	{

	}
public:
	~Wait()
	{

	}
	static Wait* Instance()								//Wait状態のインスタンス
	{
		static Wait pInstance;
		return &pInstance;
	}
	StateBase* Update(Enemy*enemy)override;	//Enemyの状態を返す
private:
	int counter;
};

#endif//#define STATE_WAIT_H_
