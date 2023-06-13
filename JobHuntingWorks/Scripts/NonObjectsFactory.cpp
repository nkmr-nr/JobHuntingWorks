
#include "NonObjectsFactory.h"
#include"Camera.h"

NonObjects* NonObjectsFactory::CreateCamera(Objects* target)
{
	return Camera::Instance(target);
}
