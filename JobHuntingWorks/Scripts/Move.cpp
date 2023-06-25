
#include "Move.h"
#include"Chase.h"
#include <stdlib.h>
#include"Enemy.h"
#include <math.h>

StateBase* Move::Update(Enemy* enemy)
{
	enemy->Move();

	counter++;

	VECTOR direction = enemy->GetTargetDirectionZX();
	const float speed = 5;

	direction.x *= speed;
	direction.z *= speed;

	enemy->SetMoveVector(direction);

	if (counter >= 300)
	{
		counter = 0;

		return Wait::Instance();
	}
	else if (enemy->IsFound() == true)
	{
		return Chase::Instance();
	}

	//float rad = atan2f(-direction.x, -direction.z);
	//VECTOR rotateDegree = enemy->GetRotateDegree();
	//rotateDegree.y = rad * (180 / DX_PI);
	//enemy->GetAngle(rotateDegree.y);

	return this;
}
