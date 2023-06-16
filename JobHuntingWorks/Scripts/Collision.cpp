
#include "Collision.h"
#include <math.h>

void Collision::Init()
{

}

void Collision::Update()
{

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

bool Collision::OnCollisionOBBAndRect()
{
	VECTOR vec = VSub(player->GetPos(), enemy->GetPos());

	vec.x = sqrtf(vec.x);
	vec.z = sqrtf(vec.z);

	VECTOR size = VAdd(player->GetScale(), enemy->GetScale());
	size.x = size.x / 2.0f;
	size.z = size.z / 2.0f;

	if (vec.x <= size.x && vec.z <= size.z)
	{
		return true;
	}
	return false;
}
