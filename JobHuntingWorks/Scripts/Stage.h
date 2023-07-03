//#pragma once
#ifndef STAGE_H_
#define STAGE_H_

#include"Objects.h"

class Stage : public Object
{
public:
	Stage(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_)
		:Object(pos_, rotateDegree_, scale_,modelHandle_,modelHandle_,0)
	{

	}
	~Stage()
	{

	}
public:
	void Init()override;				//‰Šú‰»
	void Update()override;			//XV
	void Draw()override;			//•`‰æ
};

#endif//#define STAGE_H_
