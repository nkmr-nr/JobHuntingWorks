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
	static Collision* Instance(Object* player_, Object* enemy_, RectCollider* rectInfo01_, RectCollider* rectInfo02_)				//Collider�̃C���X�^���X
	{
		static Collision pInstance(player_,enemy_,rectInfo01_,rectInfo02_);
		return &pInstance;
	}
	void Init()override;
	void Update()override;
	bool OnCollisionRectAndRect();
	bool Intersects(const OBBCollider& obb, const RectCollider& rect);
	OBBCollider ConvertToOBBCollider(const RectCollider& rect);//��`���s��ɂ��Ă�B
	float DotProduct(const VECTOR& a, const VECTOR& b);			//���ςœ����O���̌v�Z
	bool Overlap(float minA, float maxA, float minB, float maxB);// 2�̑傫�����d�Ȃ��Ă��邩�ǂ����v�Z
	bool IntersectsOBB(const OBBCollider& obbA, const OBBCollider& obbB);//�e���_�������O���̌v�Z
private:
	Object* player;																																							//Player���
	Object* enemy;																																							//Enemy���
	RectCollider* rectInfo01;																																			//��`�̏��
	RectCollider* rectInfo02;																																			//��`�̏��
};

#endif//#define COLLISION_H_
