
#include "Move.h"
#include"Chase.h"
#include <stdlib.h>
#include"Enemy.h"

StateBase* Move::Update(Enemy* enemy)
{
	if (enemy->IsFound() == true)
	{
		return Chase::Instance();
	}
	rand() % 360;
	return this;
}
