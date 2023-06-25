
#include"Wait.h"
#include "Chase.h"
#include"Enemy.h"

StateBase* Chase::Update(Enemy* enemy)
{
	VECTOR direction = enemy->GetTargetDirectionZX();
	const float speed = 5;

	direction.x *= speed;
	direction.z *= speed;

	enemy->SetMoveVector(direction);

	enemy->Move();

	if (enemy->IsFound() == false)
	{
		return Wait::Instance();
	}

	//float rad = atan2f(-direction.x, -direction.z);
	//VECTOR rotateDegree = enemy->GetRotateDegree();
	//rotateDegree.y = rad * (180 / DX_PI);
	//enemy->GetAngle(rotateDegree.y);

	return this;
}
