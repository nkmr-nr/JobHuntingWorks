
#include"Wait.h"
#include "Chase.h"
#include"Enemy.h"

StateBase* Chase::Update(Enemy* enemy)
{
	VECTOR direction = enemy->GetTargetDerectionXZ();
	const int  speed = 5;

	direction.x *= speed;
	direction.z *= speed;

	enemy->SetMoveVec(direction);

	enemy->MoveVec(direction);//移動

	if (enemy->IsFound() == false)
	{
		return Wait::Instance();//範囲内にいないからWaitに返る
	}
	return this;
}
