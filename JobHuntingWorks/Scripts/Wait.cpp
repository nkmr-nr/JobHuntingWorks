
#include "Wait.h"
#include"Enemy.h"
#include"StateBase.h"

StateBase* Wait::Update(Enemy* enemy)
{
	enemy->SearchRange();
	return this;
}
