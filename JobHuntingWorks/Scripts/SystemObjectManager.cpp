
#include "SystemObjectManager.h"

bool SystemObjectManager::Entry(SystemObject* nonObj)
{
	if (nonObj == nullptr)
	{
		return false;
	}
	nonObjects.push_back(nonObj);

	return true;
}

void SystemObjectManager::Init()
{
	for (SystemObject* nonObj : nonObjects)
	{
		nonObj->Init();
	}
}

void SystemObjectManager::Update()
{
	for (SystemObject* nonObj : nonObjects)
	{
		nonObj->Update();
	}
}
