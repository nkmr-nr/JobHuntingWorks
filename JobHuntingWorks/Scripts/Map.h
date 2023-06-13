//#pragma once
#ifndef MAP_H_
#define MAP_H_

#include"Objects.h"

class Map : public Objects
{
public:
	Map(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_)
		:Objects(pos_, rotateDegree_, scale_,modelHandle_,modelHandle_,0)
	{

	}
	~Map()
	{

	}
public:
	void Init()override;				//‰Šú‰»
	void Update()override;			//XV
	void Draw()override;			//•`‰æ
};

#endif//#define MAP_H_
