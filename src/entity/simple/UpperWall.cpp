#include "../../../inc/entity/simple/UpperWall.hpp"

std::shared_ptr<int> UpperWall::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(8);
}
