//#pragma once
#ifndef COLLISION_H_
#define COLLISION_H_

#include"Collider.h"
#include"Objects.h"
#include "SystemObject.h"
#include"Enemy.h"
#include"Player.h"

class Collision : public SystemObject
{
private:
	Collision(Player*player_, Enemy* enemy_)
		:player(player_)
		,enemy(enemy_)
	{

	}
public:
	~Collision()
	{

	}
	static Collision* Instance(Player* player_, Enemy* enemy_)			//Collider�̃C���X�^���X
	{
		static Collision pInstance(player_,enemy_);
		return &pInstance;
	}
	void Init()override;
	void Update()override;
	bool CheckCollision(RectCollider& rect, OBBCollider& obb);		//�����蔻��
	bool SeparatingAxisTest(const VECTOR& rectPos, const VECTOR& edgeDir, float rectHalfWidth, float rectHalfHeight, float rectHalfDepth,
		const VECTOR& obbCenter, const VECTOR& obbSize, const VECTOR obbAxis[3], float obbMin, float obbMax);
																							//���̂������O�����肵�Ă�
private:
	Player* player;																		//Player���
	Enemy* enemy;																	//Enemy���
};

#endif//#define COLLISION_H_
