//#pragma once
#ifndef SYSTEM_OBJECT_FACTORY_H_
#define SYSTEM_OBJECT_FACTORY_H_

#include"Objects.h"
#include"SystemObject.h"
#include"Collider.h"
#include"Player.h"
#include"Enemy.h"

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
	SystemObject* CreateCamera(Object* target);								//�J�����̃C���X�^���X
	SystemObject* CreateCollision(Player* player_, Enemy* enemy_);	//�����蔻��̃C���X�^���X
};

#endif//#define SYSTEM_OBJECT_FACTORY_H_
