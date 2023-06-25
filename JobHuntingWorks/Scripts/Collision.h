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
	static Collision* Instance(Objects* player_, Objects* enemy_, RectInfomation* rectInfo01_, RectInfomation* rectInfo02_)				//Collider�̃C���X�^���X
	{
		static Collision pInstance(player_,enemy_,rectInfo01_,rectInfo02_);
		return &pInstance;
	}
	void Init()override;
	void Update()override;
	void Draw()override;
	bool OnCollisionRectAndRect();
	bool Intersects(const OBBCollider& obb, const RectInfomation& rect);
	OBBCollider ConvertToOBBCollider(const RectInfomation& rect);//��`���s��ɂ��Ă�B
	float DotProduct(const VECTOR& a, const VECTOR& b);			//���ςœ����O���̌v�Z
	bool Overlap(float minA, float maxA, float minB, float maxB);// 2�̑傫�����d�Ȃ��Ă��邩�ǂ����v�Z
	bool IntersectsOBB(const OBBCollider& obbA, const OBBCollider& obbB);//�e���_�������O���̌v�Z
private:
	Objects* player;																																							//Player���
	Objects* enemy;																																							//Enemy���
	RectInfomation* rectInfo01;																																			//��`�̏��
	RectInfomation* rectInfo02;																																			//��`�̏��
};

#endif//#define COLLISION_H_
