#include "../../../inc/entity/simple/BottomWall.hpp"

std::shared_ptr<int> BottomWall::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(10);
}
