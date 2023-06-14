#include "Collision.h"

bool Collision::OnCollisionRectAndRect(RectInfomation* rect01, RectInfomation* rect02)
{
	return false;
}

bool Collision::OnCollisionOBBAndRect(OBBCollider* obbCollider, RectInfomation* rect)
{
	return false;
}
