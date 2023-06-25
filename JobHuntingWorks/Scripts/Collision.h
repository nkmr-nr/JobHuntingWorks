//#pragma once
#ifndef COLLISION_H_
#define COLLISION_H_

#include"Collider.h"
#include "Objects.h"

class Collision : public Objects
{
private:
	Collision(Objects*player_,Objects* enemy_,RectInfomation*rectInfo01_,RectInfomation*rectInfo02_)
		:Objects(VGet(0,0,0),VGet(0,0,0),VGet(0,0,0),-1,-1,-1)
		,player(player_)
		,enemy(enemy_)
		,rectInfo01(rectInfo01_)
		,rectInfo02(rectInfo02_)
	{

	}
public:
	~Collision()
	{

	}
	static Collision* Instance(Objects* player_, Objects* enemy_, RectInfomation* rectInfo01_, RectInfomation* rectInfo02_)				//Colliderのインスタンス
	{
		static Collision pInstance(player_,enemy_,rectInfo01_,rectInfo02_);
		return &pInstance;
	}
	void Init()override;
	void Update()override;
	void Draw()override;
	bool OnCollisionRectAndRect();
	bool Intersects(const OBBCollider& obb, const RectInfomation& rect);
	OBBCollider ConvertToOBBCollider(const RectInfomation& rect);//矩形を行列にしてる。
	float DotProduct(const VECTOR& a, const VECTOR& b);			//内積で内か外かの計算
	bool Overlap(float minA, float maxA, float minB, float maxB);// 2つの大きさが重なっているかどうか計算
	bool IntersectsOBB(const OBBCollider& obbA, const OBBCollider& obbB);//各頂点が内か外かの計算
private:
	Objects* player;																																							//Player情報
	Objects* enemy;																																							//Enemy情報
	RectInfomation* rectInfo01;																																			//矩形の情報
	RectInfomation* rectInfo02;																																			//矩形の情報
};

#endif//#define COLLISION_H_
