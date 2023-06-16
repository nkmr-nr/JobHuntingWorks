
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

	enemy->MoveVec(direction);//ˆÚ“®

	if (enemy->IsFound() == false)
	{
		return Wait::Instance();//”ÍˆÍ“à‚É‚¢‚È‚¢‚©‚çWait‚É•Ô‚é
	}
	return this;
}
