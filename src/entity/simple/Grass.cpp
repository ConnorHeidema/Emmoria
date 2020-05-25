#include "../../../inc/entity/simple/Grass.hpp"
#include <iostream>

void Grass::Update()
{
	(*p_tmp) = (*p_tmp + 1) % 4;
}

std::shared_ptr<int> Grass::GetSubTextureIndexPtr()
{
	return p_tmp;
}
