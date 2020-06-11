#include "entity/simple/UpperWall.hpp"

UpperWall::UpperWall(
	std::shared_ptr<SharedParameters> pSharedParameters,
	std::shared_ptr<TileMap> pTileMap,
	bsoncxx::array::element element)
		: IGridded(pSharedParameters, pTileMap)
{}

std::shared_ptr<int> UpperWall::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(8);
}
