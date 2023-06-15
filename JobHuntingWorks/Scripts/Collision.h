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
	static Collision* Instance()																				//Collider�̃C���X�^���X
	{
		static Collision pInstance;
		return &pInstance;
	}
	bool OnCollisionRectAndRect(RectInfomation*rect01,RectInfomation*rect02);		//��`�Ƌ�`�̓����蔻��
	bool OnCollisionOBBAndRect(Objects*player, RectInfomation* rect);	//OBBCollider�Ƌ�`�̓����蔻��
};

#endif//#define COLLISION_H_
