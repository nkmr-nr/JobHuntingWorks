//#pragma once
#ifndef SYSTEM_OBJECT_MANAGER_H_
#define SYSTEM_OBJECT_MANAGER_H_

#include<list>
#include"SystemObject.h"

class SystemObjectManager
{
private:
	SystemObjectManager()
	{

	}
public:
	~SystemObjectManager()
	{

	}
	static SystemObjectManager* Instance()					//NonObjectsManager�̃C���X�^���X
	{
		static SystemObjectManager pInstance;
		return &pInstance;
	}
public:
	bool Entry(SystemObject* nonObj);						//��I�u�W�F�N�g�̓o�^
	void Init();														//������
	void Update();													//�X�V
private:
	std::list<SystemObject*>systemObjects;						//�I�u�W�F�N�g�̊Ǘ������Ă�
};

#endif//#define SYSTEM_OBJECT_MANAGER_H_
