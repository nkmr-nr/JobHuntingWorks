
#include "Map.h"

void Map::Init()
{
	modelHandle = MV1LoadModel("Res/Island/Island.mv1");
	if (modelHandle == -1)
	{
		DxLib_End();
	}
}

void Map::Update()
{

}

void Map::Draw()
{
	MV1SetPosition(modelHandle, pos);
	MV1SetRotationXYZ(modelHandle, rotateDegree);
	MV1SetScale(modelHandle, scale);
	MV1DrawModel(modelHandle);
}
