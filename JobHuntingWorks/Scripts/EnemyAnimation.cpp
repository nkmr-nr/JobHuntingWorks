
#include "EnemyAnimation.h"
#include"Enemy.h"

void EnemyAnimation::Init()
{
	for (int i = 0; i < (int)EnemyAnimationKind::EnemyAnimMax; i++)
	{
		enemyAnimInfo[i].animationCount = MV1GetAnimTotalTime(enemy->GetModelHandle(), enemyAnimInfo[i].id);
	}
	enemyAnimationKind = EnemyAnimationKind::EnemyIdle;
	animTimer = 0.0f;
}

void EnemyAnimation::Update()
{
	if (enemyAnimationKind != EnemyAnimationKind::EnemyIdle)
	{
		enemyAnimationKind = EnemyAnimationKind::EnemyIdle;
		animTimer = 0.0f;
	}
	animTimer++;
	if (animTimer >= enemyAnimInfo[(int)enemyAnimationKind].animationCount)
	{
		animTimer = 0.0f;
	}
}

void EnemyAnimation::Draw()
{
	MV1DetachAnim(enemy->GetModelHandle(), 0);
	MV1AttachAnim(enemy->GetModelHandle(), enemyAnimInfo[(int)enemyAnimationKind].id);
	MV1SetAttachAnimTime(enemy->GetModelHandle(), 0, animTimer);
}
