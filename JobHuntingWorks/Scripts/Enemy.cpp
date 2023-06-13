
#include "Enemy.h"
#include <math.h>
#include"Player.h"

void Enemy::Init()
{
	modelHandle = MV1LoadModel("Res/Monk.mv1");
	if (modelHandle == -1)
	{
		DxLib_End();
	}
	//EnemyAnimationの初期化
	enemyAnim->Init();
}

void Enemy::Update()
{
	StateBase* before = state;
	StateBase* result = state->Update(this);
	if (before != result)
	{
		state = result;
		counter = 0;
	}
	//EnemyAnimationの更新
	enemyAnim->Update();
	//ステージの当たり判定
	OnCollisionStage();
}

void Enemy::Draw()
{
	MV1SetPosition(modelHandle, pos);
	MV1SetScale(modelHandle,scale);
	MV1SetRotationXYZ(modelHandle, rotateDegree);
	MV1DrawModel(modelHandle);
	//EnemyAnimationの描画
	enemyAnim->Draw();
}

bool Enemy::SearchRange()
{
	float rad = rotateDegree.y * DX_PI / 180.0f;

	VECTOR direction = VGet(0, 0, 0);

	direction.x = sinf(rad);
	direction.z = cosf(rad);

	VECTOR to_target = VSub(player->GetPos(), pos);

	float length = sqrtf(to_target.x * to_target.x + to_target.z * to_target.z);
	float radius = 50.0f;

	if (radius < length)
	{
		return false;
	}

	VECTOR normal = VGet(to_target.x / length, 0.0f, to_target.z / length);
	float cos = normal.x * direction.x + normal.z * direction.z;

	float arc_rad = 45.0f * DX_PI / 180.0f;
	float arc_cos = cosf(arc_rad);

	if (cos >= arc_cos)
	{
		return true;
	}
}
