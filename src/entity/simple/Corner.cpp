#include "../../../inc/entity/simple/Corner.hpp"

std::shared_ptr<int> Corner::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(5);
}
