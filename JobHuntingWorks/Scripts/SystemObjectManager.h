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
	static SystemObjectManager* Instance()					//NonObjectsManagerのインスタンス
	{
		static SystemObjectManager pInstance;
		return &pInstance;
	}
public:
	bool Entry(SystemObject* nonObj);						//非オブジェクトの登録
	void Init();														//初期化
	void Update();													//更新
private:
	std::list<SystemObject*>systemObjects;						//オブジェクトの管理をしてる
};

#endif//#define SYSTEM_OBJECT_MANAGER_H_
