#include "NonObjectsManager.h"

bool NonObjectsManager::Entry(NonObjects* nonObj)
{
	if (nonObj == nullptr)
	{
		return false;
	}
	nonObjects.push_back(nonObj);

	return true;
}

void NonObjectsManager::Init()
{
	for (NonObjects* nonObj : nonObjects)
	{
		nonObj->Init();
	}
}

void NonObjectsManager::Update()
{
	for (NonObjects* nonObj : nonObjects)
	{
		nonObj->Update();
	}
}
