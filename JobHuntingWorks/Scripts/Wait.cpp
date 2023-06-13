
#include "Wait.h"
#include"Enemy.h"
#include"StateBase.h"
#include"Chase.h"
#include"Move.h"

StateBase* Wait::Update(Enemy* enemy)
{
	int counter = enemy->GetCounter();
	if (counter >= 180)
	{
		return Move::Instance();
	}
	if (enemy->SearchRange() == true)
	{
		return Chase::Instance();
	}
	return this;
}
