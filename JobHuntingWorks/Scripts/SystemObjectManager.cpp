
#include "SystemObjectManager.h"

bool SystemObjectManager::Entry(SystemObject* systemObj)
{
	if (systemObj == nullptr)
	{
		return false;
	}
	systemObjects.push_back(systemObj);

	return true;
}

void SystemObjectManager::Init()
{
	for (SystemObject* nonObj : systemObjects)
	{
		nonObj->Init();
	}
}

void SystemObjectManager::Update()
{
	for (SystemObject* nonObj : systemObjects)
	{
		nonObj->Update();
	}
}
