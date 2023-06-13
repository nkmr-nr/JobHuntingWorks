
#include "Wait.h"
#include"Enemy.h"
#include"StateBase.h"
#include"Chase.h"

StateBase* Wait::Update(Enemy* enemy)
{
	if (enemy->SearchRange() == true)
	{
		return Chase::Instance();
	}
	return this;
}
