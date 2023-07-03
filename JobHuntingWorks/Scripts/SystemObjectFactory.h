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
	SystemObject* CreateCamera(Object* target);								//カメラのインスタンス
	SystemObject* CreateCollision(Player* player_, Enemy* enemy_);	//当たり判定のインスタンス
};

#endif//#define SYSTEM_OBJECT_FACTORY_H_
