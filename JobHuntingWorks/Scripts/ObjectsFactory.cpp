
#include "ObjectsFactory.h"

Objects* ObjectsFactory::CreatePlayer(VECTOR pos_, VECTOR rad_, VECTOR scale_, int modelHandle_, int stageHandle_, int healthPoint_)
{
	return new Player(pos_,rad_,scale_,modelHandle_,stageHandle_,healthPoint_);
}

Objects* ObjectsFactory::CreateEnemy(VECTOR pos_, VECTOR rad_, VECTOR scale_, int modelHandle_, int stageHandle_,int healthPoint_)
{
	return nullptr;
}