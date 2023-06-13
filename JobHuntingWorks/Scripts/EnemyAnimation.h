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
	static EnemyAnimation* Instance(Enemy* enemy_)//EnemyAnimationのインスタンス
	{
		static EnemyAnimation pInstance(enemy_);
		return &pInstance;
	}
public:
	void Init();
	void Update();
	void Draw();
private:
	enum EnemyAnimationKind					//Enemyのアニメーションの種類
	{
		EnemyIdle,										//待機モーション
		EnemyRun,										//走ってるモーション
		EnemyAttack,									//攻撃モーション
		EnemyTakingDamage,						//ダメージモーション

		EnemyAnimMax,								//アニメーションの数
	};
private:
	//配列にしたかったので構造体にした
	struct EnemyAnimationInfomation			//Enemyのアニメーション情報
	{
		int id;
		float animationCount;
	};
private:
	//アニメーションの情報構造体
	EnemyAnimationInfomation enemyAnimInfo[EnemyAnimationKind::EnemyAnimMax] = 
	{
		{3,0},												//待機モーションの情報
		{9,0},												//走りモーションの情報
		{11,0},											//攻撃モーションの情報
		{6,0},												//ダメージモーションの情報
	};
private:
	Enemy* enemy;											//Enemy情報
	EnemyAnimationKind enemyAnimationKind;	//Enemyのアニメションの種類
	float animTimer;											//アニメーションの時間
};

#endif//#define ENEMY_ANIMATION_H_
