//#pragma once
#ifndef NON_OBJECTS_FACTORY_H_
#define NON_OBJECTS_FACTORY_H_

#include"Objects.h"
#include"NonObjects.h"

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
	NonObjects* CreateCamera(Objects* target);
};

#endif//#define NON_OBJECTS_FACTORY_H_
