//#pragma once
#ifndef GOAL_H_
#define GOAL_H_

#include"Objects.h"

class Goal : public Objects
{
private:
	Goal(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_, int stageHandle_, int healthPoint_)
		:Objects(pos_,rotateDegree_,scale_,modelHandle_,stageHandle_,healthPoint_)
	{

	}
public:
	~Goal()
	{
	}
	static Goal* Instance(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_, int stageHandle_, int healthPoint_)
	{
		static Goal pInstance(pos_, rotateDegree_, scale_, modelHandle_, stageHandle_, healthPoint_);
		return &pInstance;
	}
	void Init()override;
	void Update()override;
	void Draw()override;
private:
};

#endif//#define GOAL_H_
