//#pragma once
#ifndef ENEMY_ANIMATION_H_
#define ENEMY_ANIMATION_H_

#include"Objects.h"

class Enemy;

class EnemyAnimation
{
private:
	EnemyAnimation(Enemy* enemy_)
		:enemy(enemy_)
		, enemyAnimationKind(EnemyAnimationKind::EnemyIdle)
		, animTimer(0.0f)
	{
	}
public:
	~EnemyAnimation()
	{
	}
	static EnemyAnimation* Instance(Enemy* enemy_)//EnemyAnimation�̃C���X�^���X
	{
		static EnemyAnimation pInstance(enemy_);
		return &pInstance;
	}
public:
	void Init();
	void Update();
	void Draw();
private:
	enum EnemyAnimationKind					//Enemy�̃A�j���[�V�����̎��
	{
		EnemyIdle,										//�ҋ@���[�V����
		EnemyRun,										//�����Ă郂�[�V����
		EnemyAttack,									//�U�����[�V����
		EnemyTakingDamage,						//�_���[�W���[�V����

		EnemyAnimMax,								//�A�j���[�V�����̐�
	};
private:
	//�z��ɂ����������̂ō\���̂ɂ���
	struct EnemyAnimationInfomation			//Enemy�̃A�j���[�V�������
	{
		int id;
		float animationCount;
	};
private:
	//�A�j���[�V�����̏��\����
	EnemyAnimationInfomation enemyAnimInfo[EnemyAnimationKind::EnemyAnimMax] = 
	{
		{3,0},												//�ҋ@���[�V�����̏��
		{9,0},												//���胂�[�V�����̏��
		{11,0},											//�U�����[�V�����̏��
		{6,0},												//�_���[�W���[�V�����̏��
	};
private:
	Enemy* enemy;											//Enemy���
	EnemyAnimationKind enemyAnimationKind;	//Enemy�̃A�j���V�����̎��
	float animTimer;											//�A�j���[�V�����̎���
};

#endif//#define ENEMY_ANIMATION_H_
