#include "entity/simple/LeftWall.hpp"

std::shared_ptr<int> LeftWall::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(6);
}
