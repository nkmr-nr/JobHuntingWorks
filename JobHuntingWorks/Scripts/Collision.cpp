
#include "Collision.h"
#include <math.h>
#include <cfloat>
#include<iostream>

void Collision::Init()
{

}

void Collision::Update()
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

bool Collision::Intersects(const OBBCollider& obb, const RectCollider& rect)
{
	OBBCollider rectOBB = ConvertToOBBCollider(rect);

	if (IntersectsOBB(obb, rectOBB) == true)
	{
		printf("a");// 当たり判定(DEBUG用)
	}
	return IntersectsOBB(obb, rectOBB);
}

OBBCollider Collision::ConvertToOBBCollider(const RectCollider& rect)
{

	OBBCollider obb = { VGet(200.0f, 30.0f, 30.0f), VGet(-100.0f, 10.0f, 0.0f) };
	obb.size = rect.rectSize;
	obb.offset = rect.pos;

	VECTOR half_size = VScale(obb.size, 0.5f);
	//矩形の各頂点情報
	VECTOR vertices[] =
	{
		VGet(-half_size.x, -half_size.y, -half_size.z),
		VGet(-half_size.x, half_size.y, -half_size.z),
		VGet(half_size.x, -half_size.y, -half_size.z),
		VGet(half_size.x, half_size.y, -half_size.z),
		VGet(-half_size.x, -half_size.y, half_size.z),
		VGet(-half_size.x, half_size.y, half_size.z),
		VGet(half_size.x, -half_size.y, half_size.z),
		VGet(half_size.x, half_size.y, half_size.z),
	};

	for (int i = 0; i < OBBCollider::MaxVertex; i++)
	{
		obb.verticesPos[i] = vertices[i];
	}
	return obb;
}

float Collision::DotProduct(const VECTOR& a, const VECTOR& b)
{
	return VDot(a, b);
}

bool Collision::Overlap(float minA, float maxA, float minB, float maxB)
{
	if (minA > maxB || minB > maxA)
	{
		return false;
	}
	return true;
}

bool Collision::IntersectsOBB(const OBBCollider& obbA, const OBBCollider& obbB)
{
	VECTOR axes[] = { obbA.axis[0], obbA.axis[1], obbA.axis[2], obbB.axis[0], obbB.axis[1], obbB.axis[2] };

	for (int i = 0; i < 6; i++)
	{
		float minA = FLT_MAX;
		float maxA = FLT_MIN;
		for (int j = 0; j < 8; j++)
		{
			float val = DotProduct(obbA.verticesPos[j], axes[i]);
			minA = min(minA, val);
			maxA = max(maxA, val);
		}

		float minB = FLT_MAX;
		float maxB = FLT_MIN;
		for (int j = 0; j < 8; j++)
		{
			float val = DotProduct(obbB.verticesPos[j], axes[i]);
			minB = min(minB, val);
			maxB = max(maxB, val);
		}

		if (!Overlap(minA, maxA, minB, maxB))
		{
			return false;
		}
	}
	return true;
}