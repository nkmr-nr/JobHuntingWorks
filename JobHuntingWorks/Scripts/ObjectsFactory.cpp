
#include "ObjectsFactory.h"

Player* ObjectsFactory::CreatePlayer(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_, int stageHandle_, int healthPoint_)
{
	return new Player(pos_, rotateDegree_,scale_,modelHandle_,stageHandle_,healthPoint_);
}

Enemy* ObjectsFactory::CreateEnemy(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_, int stageHandle_,int healthPoint_, Object*player_)
{
	return new Enemy(pos_, rotateDegree_, scale_, modelHandle_, stageHandle_, healthPoint_,player_);
}

Object* ObjectsFactory::CreateStage(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_)
{
	return new Stage(pos_,rotateDegree_,scale_,modelHandle_);
}

Object* ObjectsFactory::CreateGoal(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_, int stageHandle_, int healthPoint_)
{
	return new Goal(pos_, rotateDegree_, scale_, modelHandle_, stageHandle_, healthPoint_);
}

