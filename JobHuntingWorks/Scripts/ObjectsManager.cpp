
#include"ObjectsManager.h"

bool ObjectsManager::Entry(Object* obj)
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
	for (Object* obj : objects)
	{
		if (obj->IsActive() == true)
		{
			obj->Init();
		}
	}
}

void ObjectsManager::Update()
{
	for (Object* obj : objects)
	{
		if (obj->IsActive() == true)
		{
			obj->Update();
		}
	}
}

void ObjectsManager::Draw()
{
	for (Object* obj : objects)
	{
		if (obj->IsActive() == true)
		{
			obj->Draw();
		}
	}
}

void ObjectsManager::DeleteOnes()
{
	for (auto itr = objects.begin(); itr != objects.end(); )
	{
		if ((*itr)->IsActive() == false)
		{
			delete (*itr);
			itr = objects.erase(itr);
		}
		else
		{
			itr++;
		}
	}
}

void ObjectsManager::DeleteAll()
{
	for (auto itr = objects.begin(); itr != objects.end(); )
	{
		delete (*itr);
		itr = objects.erase(itr);
	}

	objects.clear();
}
