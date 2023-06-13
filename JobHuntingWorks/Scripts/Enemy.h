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
	void Init()override;				//‰Šú‰»
	void Update()override;			//XV
	void Draw()override;			//•`‰æ
private:
	StateBase* state;					//Enemy‚Ìó‘Ô
};

#endif//#define ENEMMY_H_
