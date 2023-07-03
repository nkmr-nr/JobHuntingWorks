
#include "SystemObjectFactory.h"
#include"Camera.h"
#include "Collision.h"

SystemObject* SystemObjectFactory::CreateCamera(Object* target)
{
	return Camera::Instance(target);
}
SystemObject* SystemObjectFactory::CreateCollision(Object* player_, Object* enemy_, RectCollider* rect01_, RectCollider* rect02_)
{
	return Collision::Instance(player_, enemy_, rect01_, rect02_);
}