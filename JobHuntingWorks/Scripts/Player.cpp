
#include "Player.h"

//�f�o�b�O�p
#ifdef DEBUG_COLLISION
int g_BoxHandle = -1;
#endif

void Player::Init()
{
	modelHandle = MV1LoadModel("Res/Warrior.mv1");
	stageHandle = MV1LoadModel("Res/Island/Island.mv1");
	playerAnim->Init();
	//�f�o�b�O�p
#ifdef DEBUG_COLLISION
	g_BoxHandle = MV1LoadModel("Res/Box.mv1");
#endif
}

void Player::Update()
{
	int speed = 5;
	int rotateSpeed = 5;

	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		isAttacking = true;
	}
	if (CheckHitKey(KEY_INPUT_SPACE) == 0)
	{
		isAttacking = false;
	}
	if (CheckHitKey(KEY_INPUT_W) && isAttacking == false)
	{
		float degree = (rotateDegree.y * (DX_PI / 180));

		VECTOR vec = VGet(-sinf(degree), 0, -cosf(degree));
		vec = VScale(vec, speed);

		pos = VAdd(pos, vec);
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) && isAttacking == false)
	{
		rotateDegree.y += rotateSpeed;
	}
	if (CheckHitKey(KEY_INPUT_LEFT) && isAttacking == false)
	{
		rotateDegree.y -= rotateSpeed;
	}
	// ���[���h�s��̍X�V
	UpdateMatrix();
	//�v���C���[�A�j���[�V�����̍X�V
	playerAnim->Update();
	//�X�e�[�W�Ƃ̓����蔻��
	OnCollisionStage();
}

void Player::UpdateMatrix()
{
	CreateIdentityMatrix(&worldMatrix);

	// �g�k�A��]�A�ړ��̍s��̍쐬
	float rad = rotateDegree.y * DX_PI / 180.0f;
	MATRIX scale_mat, rotate_y_mat, translate_mat;
	CreateScalingMatrix(&scale_mat, scale.x, scale.y, scale.z);
	CreateRotationYMatrix(&rotate_y_mat, rad);
	CreateTranslationMatrix(&translate_mat, pos.x, pos.y, pos.z);

	// �e�s����g���ă��[���h���W�ϊ��s����쐬
	CreateMultiplyMatrix(&worldMatrix, &worldMatrix, &scale_mat);
	CreateMultiplyMatrix(&worldMatrix, &worldMatrix, &rotate_y_mat);
	CreateMultiplyMatrix(&worldMatrix, &worldMatrix, &translate_mat);

	// ���f���ɐݒ�
	MV1SetMatrix(modelHandle, worldMatrix);
	MATRIX frame_matrix = MV1GetFrameLocalWorldMatrix(modelHandle, 31);
	collider.UpdateVertex(frame_matrix, matricesScale);

	//�f�o�b�O�p
#ifdef DEBUG_COLLISION
	MATRIX local_box_matrix, scale_mat02;
	CreateIdentityMatrix(&local_box_matrix);
	CreateScalingMatrix(&scale_mat, collider.size.x, collider.size.y, collider.size.z);
	CreateTranslationMatrix(&translate_mat, collider.offset.x, collider.offset.y, collider.offset.z);
	CreateMultiplyMatrix(&local_box_matrix, &local_box_matrix, &scale_mat);
	CreateMultiplyMatrix(&local_box_matrix, &local_box_matrix, &translate_mat);

	CreateMultiplyMatrix(&local_box_matrix, &local_box_matrix, &matricesScale);

	CreateMultiplyMatrix(&collisionBoxMatrix, &local_box_matrix, &frame_matrix);
	MV1SetMatrix(g_BoxHandle, collisionBoxMatrix);
#endif
}

void Player::Draw()
{
	MV1SetMatrix(modelHandle, worldMatrix);
	MV1DrawModel(modelHandle);
	playerAnim->Draw();
	//�f�o�b�O�p
#ifdef DEBUG_COLLISION
	MV1DrawModel(g_BoxHandle);
#endif
}
