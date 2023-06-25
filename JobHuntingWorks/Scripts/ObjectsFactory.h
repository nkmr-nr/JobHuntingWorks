//#pragma once
#ifndef OBJECTS_FACTORY_H_
#define OBJECTS_FACTORY_H_

#include"Objects.h"
#include"Player.h"
#include"Map.h"
#include"Enemy.h"
#include"Collision.h"

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
	Objects* CreateEnemy(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_, int stageHandle_,int healthPoint_,Objects*player_);								//Enemy�����
	Objects* CreateMap(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_);																										//Map�����
	Objects* CreateCollision(Objects* player_, Objects* enemy_, RectInfomation* rect01_, RectInfomation* rect02_);
};

#endif//#define FACTORY_H_
