
#include "PlayerAnimation.h"

void PlayerAnimation::Init()
{
	for (int i = 0; i < (int)PlayerAnimationKind::PlayerAnimMax; i++)
	{
		playerAnimInfo[i].animationCount = MV1GetAnimTotalTime(player->GetModelHandle(), playerAnimInfo[i].id);
	}
	playerAnimationKind = PlayerAnimationKind::PlayerIdle;
	animTimer = 0.0f;
}

void PlayerAnimation::Update()
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		int counter = 0;
		if (playerAnimationKind != PlayerAnimationKind::PlayerAttack)
		{
			playerAnimationKind = PlayerAnimationKind::PlayerAttack;
			animTimer = 0.0f;
		}
	}
	else if (CheckHitKey(KEY_INPUT_W))
	{
		if (playerAnimationKind != PlayerAnimationKind::PlayerRun)
		{
			playerAnimationKind = PlayerAnimationKind::PlayerRun;
			animTimer = 0.0f;
		}
	}

	else
	{
		if (playerAnimationKind != PlayerAnimationKind::PlayerIdle)
		{
			playerAnimationKind = PlayerAnimationKind::PlayerIdle;
			animTimer = 0.0f;
		}
	}
	animTimer++;
	if (animTimer >= playerAnimInfo[(int)playerAnimationKind].animationCount)
	{
		animTimer = 0.0f;
	}
}

void PlayerAnimation::Draw()
{
	MV1DetachAnim(player->GetModelHandle(), 0);
	MV1AttachAnim(player->GetModelHandle(), playerAnimInfo[(int)playerAnimationKind].id);
	MV1SetAttachAnimTime(player->GetModelHandle(), 0, animTimer);
}
