//#pragma once
#ifndef PLAYER_ANIMATION_H_
#define PLAYER_ANIMATION_H_

#include"Objects.h"
#include <list>
#include <vector>

class PlayerAnimation
{
private:
	PlayerAnimation(Objects* player_)
		:player(player_)
		, playerAnimationKind(PlayerAnimationKind::PlayerIdle)
		, animTimer(0.0f)
	{

	}
public:
	~PlayerAnimation()
	{
	}
	static PlayerAnimation* Instance(Objects* player_)//PlayerAnimation�̃C���X�^���X
	{
		static PlayerAnimation pInstance(player_);
		return &pInstance;
	}
public:
	void Init();
	void Update();
	void Draw();
private:
	enum PlayerAnimationKind							//Player�̃A�j���[�V�����̎��
	{
		PlayerIdle,												//�ҋ@���[�V����
		PlayerRun,												//�����Ă郂�[�V����
		PlayerAttack,											//�U�����[�V����
		PlayerTakingDamage,								//�_���[�W���[�V����

		PlayerAnimMax,										//�A�j���[�V�����̐�
	};
private:
	//�z��ɂ����������̂ō\���̂ɂ���
	struct PlayerAnimationInfomation					//Player�̃A�j���[�V�������
	{
		int id;													//DxLib.exe�Œ��ׂ�ID
		float animationCount;								//�A�j���[�V�����̎���
	};
private:
	//�A�j���[�V�����̏��\����
	PlayerAnimationInfomation playerAnimInfo[PlayerAnimationKind::PlayerAnimMax] = 
	{
		{3,0},														//�ҋ@���[�V�����̏��
		{9,0},														//���胂�[�V�����̏��
		{11,0},													//�U�����[�V�����̏��
		{6,0},														//�_���[�W���[�V�����̏��
	};
private:
	Objects* player;											//Player���
	PlayerAnimationKind playerAnimationKind;		//PlayerAnimation�̎��
	float animTimer;											//�A�j���[�V�����̎���
};

#endif//#define PLAYER_ANIMATION_H_
