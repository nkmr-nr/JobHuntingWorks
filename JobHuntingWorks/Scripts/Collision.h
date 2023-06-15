//#pragma once
#ifndef COLLISION_H_
#define COLLISION_H_

#include"Collider.h"
#include "Objects.h"

class Collision
{
private:
	Collision()
	{

	}
public:
	~Collision()
	{

	}
	static Collision* Instance()																				//Colliderのインスタンス
	{
		static Collision pInstance;
		return &pInstance;
	}
	bool OnCollisionRectAndRect(RectInfomation*rect01,RectInfomation*rect02);		//矩形と矩形の当たり判定
	bool OnCollisionOBBAndRect(Objects*player, RectInfomation* rect);	//OBBColliderと矩形の当たり判定
};

#endif//#define COLLISION_H_
