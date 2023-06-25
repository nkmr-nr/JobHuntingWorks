
#include "Collision.h"
#include <math.h>
#include <cfloat>
#include<iostream>

void Collision::Init()
{

}

void Collision::Update()
{
	OnCollisionOBBAndEnemy();
}

void Collision::Draw()
{

}

bool Collision::OnCollisionRectAndRect()
{
	VECTOR vec = VSub(rectInfo01->pos, rectInfo02->pos);

	vec.x = sqrtf(vec.x);
	vec.z = sqrtf(vec.z);

	VECTOR size = VAdd(rectInfo01->rectSize, rectInfo02->rectSize);
	size.x = size.x / 2.0f;
	size.z = size.z / 2.0f;

	if (vec.x <= size.x && vec.z <= size.z)
	{
		return true;
	}

	return false;
}

bool Collision::OnCollisionOBBAndEnemy()
{
	VECTOR vec = VSub(player->GetPos(), enemy->GetPos());

	vec.x = sqrtf(vec.x);
	vec.y = sqrtf(vec.y);
	vec.z = sqrtf(vec.z);

	VECTOR playerSize = VGet(200.0f, 30.0f, 30.0f), enemySize = VGet(10, 10, 10);
	VECTOR size = VAdd(playerSize, enemySize);
	size.x = size.x / 2.0f;
	size.y = size.y / 2.0f;
	size.z = size.z / 2.0f;

	if (vec.x <= size.x && vec.y <= size.y && vec.z <= size.z)
	{
		return true;
	}
	return false;
}

OBBCollider Collision::ConvertToOBBCollider(const RectInfomation& rect)
{
	OBBCollider obb = { VGet(200.0f, 30.0f, 30.0f), VGet(-100.0f, 10.0f, 0.0f) };
	obb.size = rect.rectSize;
	obb.offset = rect.pos;

	VECTOR half_size = VScale(obb.size, 0.5f);
	VECTOR vertices[] = {
		VGet(-half_size.x, -half_size.y, -half_size.z),
		VGet(-half_size.x, half_size.y, -half_size.z),
		VGet(half_size.x, -half_size.y, -half_size.z),
		VGet(half_size.x, half_size.y, -half_size.z),
		VGet(-half_size.x, -half_size.y, half_size.z),
		VGet(-half_size.x, half_size.y, half_size.z),
		VGet(half_size.x, -half_size.y, half_size.z),
		VGet(half_size.x, half_size.y, half_size.z),
	};

	for (int i = 0; i < OBBCollider::MaxVertex; i++) {
		obb.verticesPos[i] = vertices[i];
	}
	return obb;
}

bool Collision::Intersects(const OBBCollider& obb, const RectInfomation& rect)
{
	OBBCollider rectOBB = ConvertToOBBCollider(rect);
	// OBB同士の当たり判定を行う
	return IntersectsOBB(obb, rectOBB);  // これは以前に提供したIntersectsOBB関数を使用します
}

float dotProduct(const VECTOR& a, const VECTOR& b)
{
	return VDot(a, b);
}

// 2つのスカラー値が重なっているかどうかを判断する
bool overlap(float minA, float maxA, float minB, float maxB) 
{
	if (minA > maxB || minB > maxA) {
		return false; 
	}
	return true;
}

bool IntersectsOBB(const OBBCollider& obbA, const OBBCollider& obbB)
{
	VECTOR axes[] = { obbA.axis[0], obbA.axis[1], obbA.axis[2], obbB.axis[0], obbB.axis[1], obbB.axis[2] };

	for (int i = 0; i < 6; i++) {
		float minA = FLT_MAX;
		float maxA = FLT_MIN;
		for (int j = 0; j < 8; j++) {
			float val = dotProduct(obbA.verticesPos[j], axes[i]);
			minA = min(minA, val);
			maxA = max(maxA, val);
		}

		float minB = FLT_MAX;
		float maxB = FLT_MIN;
		for (int j = 0; j < 8; j++) {
			float val = dotProduct(obbB.verticesPos[j], axes[i]);
			minB = min(minB, val);
			maxB = max(maxB, val);
		}

		if (!overlap(minA, maxA, minB, maxB)) {
			return false; // 軸が存在しているので、OBBは重なっていない
		}
	}
	return true; // すべての軸が重なっているので、OBBは重なっている
}