//#pragma once
#ifndef OBJECTS_FACTORY_H_
#define OBJECTS_FACTORY_H_

#include"Objects.h"
#include"Player.h"
#include"Map.h"
#include"Enemy.h"

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
	static ObjectsFactory* Instance()																																															//ObjectFactoryのインスタンス
	{
		static ObjectsFactory pInstance;
		return &pInstance;
	}

	Objects* CreatePlayer(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_,int stageHandle_, int healthPoint_);														//Playerを作る
	Objects* CreateEnemy(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_, int stageHandle_,int healthPoint_,Objects*player_);								//Enemyを作る
	Objects* CreateMap(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_);																										//Mapを作る
};

#endif//#define FACTORY_H_
