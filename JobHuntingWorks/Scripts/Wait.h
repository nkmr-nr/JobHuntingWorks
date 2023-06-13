//#pragma once
#ifndef STATE_WAIT_H_
#define STATE_WAIT_H_

#include"StateBase.h"

class Wait : public StateBase
{
private:
	Wait()
		:StateBase(EnemyState::WaitState)
	{

	}
public:
	~Wait()
	{

	}
	static Wait* Instance()							//Wait状態のインスタンス
	{
		static Wait pInstance;
		return &pInstance;
	}
	void Update(Enemy*enemy)override;
	EnemyState GetEnemyState()override	//Wait状態を返す関数
	{
		return EnemyState::WaitState;
	}
};

#endif//#define STATE_WAIT_H_
