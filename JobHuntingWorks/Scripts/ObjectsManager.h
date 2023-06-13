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
		objects.clear();												//オブジェクトを消す
	}
	ObjectsManager(ObjectsManager& obj) = delete;	//コピー対策
public:
	~ObjectsManager()
	{
		DeleteAll();													//登録したのを消してる
	}
	static ObjectsManager* Instance()						//ObjectsManagerのインスタンス
	{
		static ObjectsManager pInstance;
		return &pInstance;
	}

	bool Entry(Objects* obj);
	void Init();														//初期化
	void Update();													//更新
	void Draw();													//描画
	void DeleteOnes();											//オブジェクトの削除
	void DeleteAll();												//すべてのオブジェクトの削除
	int GetObjectsNum(	)										//オブジェクトの数
	{
		return objects.size();
	}
private:
	std::list<Objects*>objects;									//Objectを管理してる
};

#endif//#define OBJECTS_MANAGER_H_
