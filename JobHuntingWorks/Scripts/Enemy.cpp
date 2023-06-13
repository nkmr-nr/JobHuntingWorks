
#include "Enemy.h"

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
