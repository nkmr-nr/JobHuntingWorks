#include "Collision.h"
#include <math.h>

bool Collision::OnCollisionRectAndRect(RectInfomation* rect01, RectInfomation* rect02)
{
	VECTOR vec = VSub(rect01->pos, rect02->pos);

	vec.x = sqrtf(vec.x);
	vec.z = sqrtf(vec.z);

	VECTOR size = VAdd(rect01->rectSize, rect02->rectSize);
	size.x = size.x / 2.0f;
	size.z = size.z / 2.0f;

	if (vec.x <= size.x && vec.z <= size.z)
	{
		return true;
	}

	return false;
}

bool Collision::OnCollisionOBBAndRect(Objects* player, RectInfomation* rect)
{
	VECTOR vec = VSub(player->GetPos(), rect->pos);

	vec.x = sqrtf(vec.x);
	vec.z = sqrtf(vec.z);

	VECTOR size = VAdd(player->GetScale(), rect->rectSize);
	size.x = size.x / 2.0f;
	size.z = size.z / 2.0f;

	if (vec.x <= size.x && vec.z <= size.z)
	{
		return true;
	}
	return false;
}
