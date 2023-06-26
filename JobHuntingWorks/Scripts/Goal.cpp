#include "Goal.h"

void Goal::Init()
{
	modelHandle = MV1LoadModel("Res/Sphere.mv1");
}

void Goal::Update()
{
	counter++;
	if (counter > 0 && counter <= 30)
	{
		pos.y += 1;
	}
	else if (counter > 30 && counter <= 60)
	{
		pos.y -= 1;
	}
	else if (counter > 61)
	{
		counter = 0;
	}
}

void Goal::Draw()
{
	MV1SetPosition(modelHandle, pos);
	MV1SetRotationXYZ(modelHandle, rotateDegree);
	MV1SetScale(modelHandle, scale);
	MV1DrawModel(modelHandle);
}
