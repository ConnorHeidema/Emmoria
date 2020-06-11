#include "entity/simple/RockGround.hpp"

RockGround::RockGround(
	std::shared_ptr<SharedParameters> pSharedParameters,
	std::shared_ptr<TileMap> pTileMap,
	bsoncxx::array::element element)
		: IGridded(pSharedParameters, pTileMap)
{}

std::shared_ptr<int> RockGround::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(7);
}
