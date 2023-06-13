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
	static PlayerAnimation* Instance(Objects* player_)//PlayerAnimationのインスタンス
	{
		static PlayerAnimation pInstance(player_);
		return &pInstance;
	}
public:
	void Init();
	void Update();
	void Draw();
private:
	enum PlayerAnimationKind							//Playerのアニメーションの種類
	{
		PlayerIdle,												//待機モーション
		PlayerRun,												//走ってるモーション
		PlayerAttack,											//攻撃モーション
		PlayerTakingDamage,								//ダメージモーション

		PlayerAnimMax,										//アニメーションの数
	};
private:
	//配列にしたかったので構造体にした
	struct PlayerAnimationInfomation					//Playerのアニメーション情報
	{
		int id;													//DxLib.exeで調べたID
		float animationCount;								//アニメーションの時間
	};
private:
	//アニメーションの情報構造体
	PlayerAnimationInfomation playerAnimInfo[PlayerAnimationKind::PlayerAnimMax] = 
	{
		{3,0},														//待機モーションの情報
		{9,0},														//走りモーションの情報
		{11,0},													//攻撃モーションの情報
		{6,0},														//ダメージモーションの情報
	};
private:
	Objects* player;											//Player情報
	PlayerAnimationKind playerAnimationKind;		//PlayerAnimationの種類
	float animTimer;											//アニメーションの時間
};

#endif//#define PLAYER_ANIMATION_H_
