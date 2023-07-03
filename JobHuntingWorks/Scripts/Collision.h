//#pragma once
#ifndef COLLISION_H_
#define COLLISION_H_

#include"Collider.h"
#include"Objects.h"
#include "SystemObject.h"

class Collision : public SystemObject
{
private:
	Collision(Object*player_, Object* enemy_, RectCollider*rectInfo01_, RectCollider*rectInfo02_)
		:player(player_)
		,enemy(enemy_)
		,rectInfo01(rectInfo01_)
		,rectInfo02(rectInfo02_)
	{

	}
public:
	~Collision()
	{

	}
	static Collision* Instance(Object* player_, Object* enemy_, RectCollider* rectInfo01_, RectCollider* rectInfo02_)				//Colliderのインスタンス
	{
		static Collision pInstance(player_,enemy_,rectInfo01_,rectInfo02_);
		return &pInstance;
	}
	void Init()override;
	void Update()override;
	bool OnCollisionRectAndRect();
	bool Intersects(const OBBCollider& obb, const RectCollider& rect);
	OBBCollider ConvertToOBBCollider(const RectCollider& rect);//矩形を行列にしてる。
	float DotProduct(const VECTOR& a, const VECTOR& b);			//内積で内か外かの計算
	bool Overlap(float minA, float maxA, float minB, float maxB);// 2つの大きさが重なっているかどうか計算
	bool IntersectsOBB(const OBBCollider& obbA, const OBBCollider& obbB);//各頂点が内か外かの計算
private:
	Object* player;																																							//Player情報
	Object* enemy;																																							//Enemy情報
	RectCollider* rectInfo01;																																			//矩形の情報
	RectCollider* rectInfo02;																																			//矩形の情報
};

#endif//#define COLLISION_H_
