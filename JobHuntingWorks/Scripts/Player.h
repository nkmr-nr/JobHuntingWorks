//#pragma once
#ifndef PLAYER_H_
#define PLAYER_H_

#include<DxLib.h>
#include"Collider.h"
#include"Objects.h"
#include"PlayerAnimation.h"

#define DEBUG_COLLISION
//デバッグ用
#ifdef DEBUG_COLLISION
extern int g_BoxHandle;
#endif

class Player : public Object
{
public:
	Player(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_,int stageHandle_,int healthPoint_)
		:Object(pos_,rotateDegree_,scale_,modelHandle_,stageHandle_,healthPoint_)
		, isAttacking(false)
		, collider(VGet(200.0f, 30.0f, 30.0f), VGet(-100.0f, 10.0f, 0.0f))
		,playerAnim(PlayerAnimation::Instance(this))
	{
		CreateIdentityMatrix(&worldMatrix);
		CreateScalingMatrix(&matricesScale, 0.01f, 0.01f, 0.01f);
//デバッグ用
#if defined DEBUG_COLLISION
		CreateIdentityMatrix(&collisionBoxMatrix);
#endif
	}
	~Player()
	{

	}
	void Init()override;
	void Update()override;
	void UpdateMatrix();
	void Draw()override;
private:
	int isAttacking;						//攻撃中かどうか

	MATRIX worldMatrix;				//ワールド座標の行列
	MATRIX matricesScale;				//拡縮用行列

	OBBCollider collider;				//コライダー
	PlayerAnimation* playerAnim;	//プレイヤーのアニメーション
#if defined DEBUG_COLLISION
	MATRIX collisionBoxMatrix;		// デバッグ用の直方体描画のための行列
#endif
};

#endif//#define PLAYER_H_
