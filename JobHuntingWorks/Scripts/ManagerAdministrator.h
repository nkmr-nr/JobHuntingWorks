//#pragma once
#ifndef MANAGER_ADMINISTRATOR_H_
#define MANAGER_ADMINISTRATOR_H_

#include"ObjectsFactory.h"
#include"ObjectsManager.h"

#include"SystemObjectFactory.h"
#include "SystemObjectManager.h"

class ManagerAdministrator//マネージャー管理者
{
private:
	ManagerAdministrator()
		:objectsManager(ObjectsManager::Instance())
		,systemObjectManager(SystemObjectManager::Instance())
		, playerInstance(ObjectsFactory::Instance()->CreatePlayer(VGet(0, 0, 0), VGet(0, 0, 0), VGet(0.4f, 0.4f, 0.4f), -1, -1, 10))
		, enemyInstance(ObjectsFactory::Instance()->CreateEnemy(VGet(-100, 0, -1000), VGet(0, 0, 0), VGet(0.5f, 0.5f, 0.5f), -1, -1, 0, playerInstance))
		, collisionInstance(SystemObjectFactory::Instance()->CreateCollision(playerInstance, enemyInstance))
	{
	}
public:
	~ManagerAdministrator()
	{

	}
	static ManagerAdministrator* Instance()
	{
		static ManagerAdministrator pInstance;
		return &pInstance;
	}
	void Init();
	void Update();
	void Draw();
	void Finish();
	bool IsDead()
	{
		return collisionInstance->CheckCollision(enemyInstance->rectCollider, playerInstance->collider);
	}
	ObjectsManager* objectsManager;
	SystemObjectManager* systemObjectManager;
	Player* playerInstance;
	Enemy* enemyInstance;
	Collision* collisionInstance;
};

#endif//#define MANAGER_ADMINISTRATOR_H_
