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
	static ObjectsFactory* Instance()																																															//ObjectFactory�̃C���X�^���X
	{
		static ObjectsFactory pInstance;
		return &pInstance;
	}

	Player* CreatePlayer(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_,int stageHandle_, int healthPoint_);														//Player�����
	Enemy* CreateEnemy(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_, int stageHandle_,int healthPoint_, Object*player_);								//Enemy�����
	Object* CreateStage(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_);																										//Map�����
	Object* CreateGoal(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_, int stageHandle_, int healthPoint_);								//Gaol�����
};

#endif//#define FACTORY_H_
