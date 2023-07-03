
#include "SystemObjectFactory.h"
#include"Camera.h"
#include "Collision.h"

SystemObject* SystemObjectFactory::CreateCamera(Object* target)
{
	return Camera::Instance(target);
}

SystemObject* SystemObjectFactory::CreateCollision(Player* player_, Enemy* enemy_)
{
	return  Collision::Instance(player_,enemy_);
}
