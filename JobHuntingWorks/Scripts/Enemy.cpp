#include "Enemy.h"

void Enemy::Init()
{
	modelHandle = MV1LoadModel("Res/Monk.mv1");
}

void Enemy::Update()
{
	state->Update();
}

void Enemy::Draw()
{

}