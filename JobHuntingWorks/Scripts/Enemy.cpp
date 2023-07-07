
#include "Enemy.h"
#include <math.h>
#include"Player.h"

void Enemy::Init()
{
	modelHandle = MV1LoadModel("Res/Monk.mv1");
	stageHandle = MV1LoadModel("Res/Island/Island.mv1");
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
	rectCollider = { &pos,&scale };
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

bool Enemy::IsFound()
{
	float rad = rotateDegree.y * (DX_PI / 180);

	VECTOR direction = VGet(0, 0, 0);
	direction.x = -sinf(rad);
	direction.z = -cosf(rad);

	VECTOR target = VSub(player->GetPos(), pos);

	float length = sqrtf((target.x * target.x) + (target.z * target.z));

	VECTOR normal = VGet(target.x / length, 0, target.z / length);

	float cos = (normal.x * direction.x) + (normal.z * direction.z);

	if (cos >= 0)
	{
		return true;
	}

	return false;
}

VECTOR Enemy::GetTargetDirectionZX()
{
	VECTOR direction = VSub(player->GetPos(), pos);
	direction.y = 0;

	float length = sqrtf((direction.x * direction.x) + (direction.z * direction.z));

	if (length > 0)
	{
		direction.x /= length;
		direction.z /= length;
	}
	return direction;
}
