//#pragma once
#ifndef OBJECTS_FACTORY_H_
#define OBJECTS_FACTORY_H_

#include"Objects.h"
#include"Player.h"
#include"Stage.h"
#include"Enemy.h"
#include"Collision.h"
#include"Goal.h"

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

	Player* CreatePlayer(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_,int stageHandle_, int healthPoint_);														//Playerを作る
	Enemy* CreateEnemy(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_, int stageHandle_,int healthPoint_, Object*player_);								//Enemyを作る
	Object* CreateStage(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_);																										//Mapを作る
	Object* CreateGoal(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_, int stageHandle_, int healthPoint_);								//Gaolを作る
};

#endif//#define FACTORY_H_
