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
	static NonObjectsManager* Instance()	//NonObjectsManagerのインスタンス
	{
		static NonObjectsManager pInstance;
		return &pInstance;
	}
public:
	bool Entry(NonObjects* nonObj);								//オブジェクトの登録
	void Init();														//初期化
	void Update();													//更新
private:
	std::list<NonObjects*>nonObjects;					//オブジェクトの管理をしてる
};

#endif//#define NON_OBJECTS_MANAGER_H_
