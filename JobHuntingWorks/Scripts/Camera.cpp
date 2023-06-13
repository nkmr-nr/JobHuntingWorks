
#include"Camera.h"
#include<math.h>
#include"Player.h"


void Camera::Init()
{
	SetTarget(targetObj);
}

void Camera::Update()
{
	VECTOR target_pos = VGet(0, 0, 0);
	if (targetObj != nullptr)
	{
		target_pos = targetObj->GetPos();
	}

	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		isAttacking = true;
	}
	if (CheckHitKey(KEY_INPUT_SPACE) == 0)
	{
		isAttacking = false;
	}
	if ( isAttacking == false)
	{

		float speed = 5;
		if (CheckHitKey(KEY_INPUT_LEFT))
		{
			rotateAngle.y -= speed;
		}
		if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			rotateAngle.y += speed;
		}

		VECTOR vec = VGet(0, 0, 0);
		float radY = rotateAngle.y * (DX_PI / 180);

		vec.x = sinf(radY);
		vec.z = cosf(radY);

		float distance = 200.0f;
		target_pos.y += 40.0f;

		vec = VScale(vec, distance);

		vec.y = 10.0f;


		SetPositionAndTarget(VAdd(target_pos, vec), target_pos);
	}
}

void Camera::FinishCamera()
{
	pos = VGet(0, 0, 0);
	target = VGet(0, 0, 0);
	rotateAngle = VGet(0, 0, 0);
}

