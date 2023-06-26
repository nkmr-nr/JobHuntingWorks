//#pragma once
#ifndef GOAL_H_
#define GOAL_H_

#include"Objects.h"

class Goal : public Objects
{
public:
	Goal(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_, int stageHandle_, int healthPoint_)
		:Objects(pos_,rotateDegree_,scale_,modelHandle_,stageHandle_,healthPoint_)
		,counter(0)
	{

	}
	~Goal()
	{
	}
	void Init()override;
	void Update()override;
	void Draw()override;
private:
	int counter;
};

#endif//#define GOAL_H_
