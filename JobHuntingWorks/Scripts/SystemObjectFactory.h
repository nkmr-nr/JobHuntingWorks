//#pragma once
#ifndef SYSTEM_OBJECT_FACTORY_H_
#define SYSTEM_OBJECT_FACTORY_H_

#include"Objects.h"
#include"SystemObject.h"
#include"Collider.h"

class SystemObjectFactory
{
private:
	SystemObjectFactory()
	{

	}
public:
	~SystemObjectFactory()
	{

	}
	static SystemObjectFactory* Instance()
	{
		static SystemObjectFactory pInstance;
		return &pInstance;
	}
	SystemObject* CreateCamera(Object* target);
	SystemObject* CreateCollision(Object* player_, Object* enemy_, RectCollider* rect01_, RectCollider* rect02_);
};

#endif//#define SYSTEM_OBJECT_FACTORY_H_
