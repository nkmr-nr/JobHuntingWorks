#include "Enemy.h"

void Enemy::Init()
{
	modelHandle = MV1LoadModel("Res/Monk.mv1");
	if (modelHandle == -1)
	{
		DxLib_End();
	}
}

void Enemy::Update()
{
	state->Update(this);
	OnCollisionStage();
}

void Enemy::Draw()
{
	MV1SetPosition(modelHandle, pos);
	MV1SetScale(modelHandle,scale);
	MV1SetRotationXYZ(modelHandle, rotateDegree);
	MV1DrawModel(modelHandle);
}
