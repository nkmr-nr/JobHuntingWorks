
#include "ManagerAdministrator.h"

void ManagerAdministrator::Init()
{
	objectsManager->Entry(playerInstance);
	objectsManager->Entry(enemyInstance);
	objectsManager->Entry(ObjectsFactory::Instance()->CreateStage(VGet(0, 0, 0), VGet(0, 0, 0), VGet(1, 1, 1), -1));
	objectsManager->Entry(ObjectsFactory::Instance()->CreateGoal(VGet(1000, 50, 1000), VGet(0, 0, 0), VGet(50, 50, 50), -1, -1, 0));

	objectsManager->Init();

	systemObjectManager->Entry(SystemObjectFactory::Instance()->CreateCamera(playerInstance));
	systemObjectManager->Entry(collisionInstance);
	systemObjectManager->Init();
}

void ManagerAdministrator::Update()
{
	IsDead();
	objectsManager->Update();
	systemObjectManager->Update();
	objectsManager->DeleteOnes();
}

void ManagerAdministrator::Draw()
{
	objectsManager->Draw();
}

void ManagerAdministrator::Finish()
{
	objectsManager->DeleteAll();
}
