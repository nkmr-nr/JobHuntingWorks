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
	static Attack* Instance()					//Attack��Ԃ̃C���X�^���X
	{
		static Attack pInstance;
		return &pInstance;
	}
	void Update(Enemy*enemy)override;						//�X�V����
	EnemyState GetEnemyState()override	//Attack��Ԃ�Ԃ��֐�
	{
		return EnemyState::AttackState;
	}
};

#endif//#define STATE_ATTACK_H_
