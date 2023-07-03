
#include "Stage.h"

void Stage::Init()
{
	modelHandle = MV1LoadModel("Res/Island/Island.mv1");
	if (modelHandle == -1)
	{
		DxLib_End();
	}
}

void Stage::Update()
{

}

void Stage::Draw()
{
	MV1SetPosition(modelHandle, pos);
	MV1SetRotationXYZ(modelHandle, rotateDegree);
	MV1SetScale(modelHandle, scale);
	MV1DrawModel(modelHandle);
}
