
#include"ObjectsManager.h"

bool ObjectsManager::Entry(Objects* obj)
{
	if (obj == nullptr)
	{
		return false;
	}
	objects.push_back(obj);

	return true;
}

void ObjectsManager::Init()
{
	for (Objects* obj : objects)
	{
		if (obj->IsActive() == true)
		{
			obj->Init();
		}
	}
}

void ObjectsManager::Update()
{
	for (Objects* obj : objects)
	{
		if (obj->IsActive() == true)
		{
			obj->Update();
		}
	}
}

void ObjectsManager::Draw()
{
	for (Objects* obj : objects)
	{
		if (obj->IsActive() == true)
		{
			obj->Draw();
		}
	}
}

void ObjectsManager::DeleteOnes()
{
	/*
	for (auto itr = objects.begin(); itr != objects.end(); itr++)
	{
		if ((*itr)->IsActive() == false)
		{
			delete(*itr);
			itr = objects.erase(itr);
		}
		else
		{
			itr++;
		}
	}
	*/
}

void ObjectsManager::DeleteAll()
{
	/*
		for (auto itr = objects.begin(); itr != objects.end(); itr++)
	{
		delete(*itr);
		itr = objects.erase(itr);
	}
	objects.clear();
	*/
}
