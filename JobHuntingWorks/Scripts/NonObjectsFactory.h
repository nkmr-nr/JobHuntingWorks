//#pragma once
#ifndef NON_OBJECTS_FACTORY_H_
#define NON_OBJECTS_FACTORY_H_

#include"Camera.h"
#include"Objects.h"

class NonObjectsFactory
{
private:
	NonObjectsFactory()
	{

	}
public:
	~NonObjectsFactory()
	{

	}
	static NonObjectsFactory* Instance()
	{
		static NonObjectsFactory pInstance;
		return &pInstance;
	}
	Camera* CreateCamera(Objects* target);
};

#endif//#define NON_OBJECTS_FACTORY_H_
