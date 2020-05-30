#include "entity/simple/RockGround.hpp"

std::shared_ptr<int> RockGround::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(7);
}
