//#pragma once
#ifndef ENEMMY_H_
#define ENEMMY_H_

#include"Objects.h"
#include"Wait.h"
#include"StateBase.h"

class Enemy : public Objects
{
public:
	Enemy(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_, int stageHandle_, int healthPoint_)
		:Objects(pos_, rotateDegree_,scale_,modelHandle_,stageHandle_,healthPoint_)
		,state(Wait::Instance())
	{

	}
	~Enemy()
	{

	}
	void Init()override;				//初期化
	void Update()override;			//更新
	void Draw()override;			//描画
private:
	StateBase* state;					//Enemyの状態
};

#endif//#define ENEMMY_H_
