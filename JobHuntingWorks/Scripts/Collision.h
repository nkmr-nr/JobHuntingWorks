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
	bool OnCollisionRectAndRect();																																		//矩形と矩形の当たり判定
	bool OnCollisionOBBAndEnemy();																																	//OBBColliderと敵の当たり判定
	OBBCollider ConvertToOBBCollider(const RectInfomation& rect);
	bool Intersects(const OBBCollider& obb, const RectInfomation& rect);
private:
	Objects* player;																																							//Player情報
	Objects* enemy;																																							//Enemy情報
	RectInfomation* rectInfo01;																																			//矩形の情報
	RectInfomation* rectInfo02;																																			//矩形の情報
};

#endif//#define COLLISION_H_
