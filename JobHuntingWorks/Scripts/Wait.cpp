
#include "Wait.h"
#include"Enemy.h"
#include"StateBase.h"
#include"Chase.h"
#include"Move.h"

StateBase* Wait::Update(Enemy* enemy)
{
	const float speed = 5;
	counter--;
	if (counter <= 0)
	{
		counter = 180;
		int degree = rand() % 360;
		float rad = (float)degree * (DX_PI / 180);
		enemy->SetMoveVector(VGet(sinf(rad * speed), 0, cosf(rad * speed)));
		return Move::Instance();
	}
	else if (enemy->IsFound() == true)
	{
		return Chase::Instance();
	}

	return this;
}
