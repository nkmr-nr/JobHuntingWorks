//#pragma once
#ifndef ENEMMY_H_
#define ENEMMY_H_

#include"Objects.h"
#include"Wait.h"
#include"StateBase.h"
#include"EnemyAnimation.h"
#include<math.h>

class Player;

class Enemy : public Objects
{
public:
	Enemy(VECTOR pos_, static VECTOR rotateDegree_, VECTOR scale_, int modelHandle_, int stageHandle_, int healthPoint_,Objects*player_)
		:Objects(pos_, rotateDegree_,scale_,modelHandle_,stageHandle_,healthPoint_)
		,state(Wait::Instance())
		,counter(0)
		,enemyAnim(EnemyAnimation::Instance(this))
		,player(player_)
		,moveVec(VGet(0,0,0))
	{

	}
	~Enemy()
	{

	}
	void Init()override;										//初期化
	void Update()override;									//更新
	void Draw()override;									//描画
	bool IsFound();											//索敵範囲
	int GetCounter()											//カウントを増やす
	{
		counter++;
		return counter;
	}
	void SetMoveVector(VECTOR vec)					//要素の値を代入
	{
		moveVec = vec;
	}
	void Move()												//決定しtベクトルに進む
	{
		float length = sqrtf((moveVec.x * moveVec.x) + (moveVec.z * moveVec.z));
		pos = VAdd(pos, moveVec);
	}
	void GetAngle(float rotateDegree_y)				//回転角度
	{
		rotateDegree.y = rotateDegree_y;
	}
	VECTOR GetTargetDirectionZX();					//敵位置算出用関数
	VECTOR GetRotateDegree()							//回転角度取得用関数
	{
		return rotateDegree;
	}
private:
	StateBase* state;											//Enemyの状態
	int counter;													//waitのcounter
	EnemyAnimation* enemyAnim;						//Enemyのアニメーション
	Objects* player;											//索敵用
	VECTOR moveVec;										//移動ベクトル
};

#endif//#define ENEMMY_H_
