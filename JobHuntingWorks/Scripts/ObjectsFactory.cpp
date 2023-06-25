
#include "ObjectsFactory.h"

Objects* ObjectsFactory::CreatePlayer(VECTOR pos_, VECTOR rad_, VECTOR scale_, int modelHandle_, int stageHandle_, int healthPoint_)
{
	return new Player(pos_,rad_,scale_,modelHandle_,stageHandle_,healthPoint_);
}

Objects* ObjectsFactory::CreateEnemy(VECTOR pos_, VECTOR rad_, VECTOR scale_, int modelHandle_, int stageHandle_,int healthPoint_,Objects*player_)
{
	return new Enemy(pos_, rad_, scale_, modelHandle_, stageHandle_, healthPoint_,player_);
}

Objects* ObjectsFactory::CreateMap(VECTOR pos_, VECTOR rotateDegree_, VECTOR scale_, int modelHandle_)
{
	return new Map(pos_,rotateDegree_,scale_,modelHandle_);
}

Objects* ObjectsFactory::CreateCollision(Objects* player_, Objects* enemy_, RectInfomation* rect01_, RectInfomation* rect02_)
{
	return Collision::Instance(player_, enemy_, rect01_, rect02_);
}
