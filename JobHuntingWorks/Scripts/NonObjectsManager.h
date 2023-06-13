//#pragma once
#ifndef NON_OBJECTS_MANAGER_H_
#define NON_OBJECTS_MANAGER_H_

#include<list>
#include"NonObjects.h"

class NonObjectsManager
{
private:
	NonObjectsManager()
	{

	}
public:
	~NonObjectsManager()
	{

	}
	static NonObjectsManager* Instance()	//NonObjectsManager�̃C���X�^���X
	{
		static NonObjectsManager pInstance;
		return &pInstance;
	}
public:
	bool Entry(NonObjects* nonObj);								//�I�u�W�F�N�g�̓o�^
	void Init();														//������
	void Update();													//�X�V
private:
	std::list<NonObjects*>nonObjects;					//�I�u�W�F�N�g�̊Ǘ������Ă�
};

#endif//#define NON_OBJECTS_MANAGER_H_
