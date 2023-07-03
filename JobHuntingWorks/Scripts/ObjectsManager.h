//#pragma once
#ifndef OBJECTS_MANAGER_H_
#define OBJECTS_MANAGER_H_

#include"Objects.h"
#include <vector>
#include<list>

class ObjectsManager
{
private:
	ObjectsManager()
	{
		objects.clear();												//�I�u�W�F�N�g������
	}
	ObjectsManager(ObjectsManager& obj) = delete;	//�R�s�[�΍�
public:
	~ObjectsManager()
	{
		DeleteAll();													//�o�^�����̂������Ă�
	}
	static ObjectsManager* Instance()						//ObjectsManager�̃C���X�^���X
	{
		static ObjectsManager pInstance;
		return &pInstance;
	}

	bool Entry(Object* obj);									//�I�u�W�F�N�g�̓o�^
	void Init();														//������
	void Update();													//�X�V
	void Draw();													//�`��
	void DeleteOnes();											//�I�u�W�F�N�g�̍폜
	void DeleteAll();												//���ׂẴI�u�W�F�N�g�̍폜
	int GetObjectsNum(	)										//�I�u�W�F�N�g�̐�
	{
		return objects.size();
	}
private:
	std::list<Object*>objects;									//Object���Ǘ����Ă�
};

#endif//#define OBJECTS_MANAGER_H_
