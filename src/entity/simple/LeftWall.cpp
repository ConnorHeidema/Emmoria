#include "entity/simple/LeftWall.hpp"

LeftWall::LeftWall(
	std::shared_ptr<SharedParameters> pSharedParameters,
	std::shared_ptr<TileMap> pTileMap,
	bsoncxx::array::element element)
		: IGridded(pSharedParameters, pTileMap)
{}

std::shared_ptr<int> LeftWall::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(6);
}
