
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
		float radY = rotateAngle.y * (DX_PI / 180);//単位円にして計算できるようにしてる

		vec.x = sinf(radY);//向きベクトルのx
		vec.z = cosf(radY);//向きベクトルのz

		float distance = 200.0f;//範囲設定
		target_pos.y += 40.0f;//カメラのoffset

		vec = VScale(vec, distance);//見える範囲の計算

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

