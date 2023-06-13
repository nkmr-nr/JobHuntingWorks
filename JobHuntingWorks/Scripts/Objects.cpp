
#include "Objects.h"

void Objects::OnCollisionStage()
{
	VECTOR ray_start = pos;
	ray_start.y += 10.0f;

	VECTOR ray_end = ray_start;
	ray_end.y -= 100.0f;

	MV1_COLL_RESULT_POLY  result = MV1CollCheck_Line(stageHandle, -1, ray_start, ray_end);

	if (result.HitFlag == 1)
	{
		pos = result.HitPosition;
	}
}
