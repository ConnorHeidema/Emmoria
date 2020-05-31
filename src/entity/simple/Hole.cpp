#include "entity/simple/Hole.hpp"

std::shared_ptr<int> Hole::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(11);
}
