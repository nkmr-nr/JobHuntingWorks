//#pragma once
#ifndef OBJECTS_FACTORY_H_
#define OBJECTS_FACTORY_H_

#include"Objects.h"
#include"Player.h"

class ObjectsFactory
{
private:
	ObjectsFactory()
	{

	}
public:
	~ObjectsFactory()
	{
		
	}
	static ObjectsFactory* Instance()																																															//ObjectFactory�̃C���X�^���X
	{
		static ObjectsFactory pInstance;
		return &pInstance;
	}

	Objects* CreatePlayer(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_,int stageHandle_, int healthPoint_);														//Player�����
	Objects* CreateEnemy(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_, int stageHandle_,int healthPoint_);													//Enemy�����
};

#endif//#define FACTORY_H_
