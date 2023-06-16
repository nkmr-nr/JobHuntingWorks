
#include "Move.h"
#include"Chase.h"
#include <stdlib.h>
#include"Enemy.h"
#include <math.h>

StateBase* Move::Update(Enemy* enemy)
{
	const int speed = 5;
	if (enemy->IsFound() == true)
	{
		return Chase::Instance();
	}
	if (isDecision == false)
	{
		degree = rand() % 360;
		isDecision = true;
	}
	
	float rad = ((float)degree * (DX_PI / 180));

	 moveVec= VGet(sinf(rad * speed), 0, cosf(rad * speed));
	enemy->MoveVec(moveVec);

	float counter = enemy->GetCounter();

	if (counter > 30)
	{
		isDecision = false;
		return Wait::Instance();
	}

	return this;
}
