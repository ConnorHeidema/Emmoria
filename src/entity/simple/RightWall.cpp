#include "entity/simple/RightWall.hpp"

std::shared_ptr<int> RightWall::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(9);
}
