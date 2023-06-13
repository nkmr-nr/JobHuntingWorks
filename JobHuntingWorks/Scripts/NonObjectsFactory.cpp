
#include "NonObjectsFactory.h"

Camera* NonObjectsFactory::CreateCamera(Objects* target)
{
	return Camera::Instance(target);
}
