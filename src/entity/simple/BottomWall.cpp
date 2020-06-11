#include "entity/simple/BottomWall.hpp"

BottomWall::BottomWall(
	std::shared_ptr<SharedParameters> pSharedParameters,
	std::shared_ptr<TileMap> pTileMap,
	bsoncxx::array::element element)
		: IGridded(pSharedParameters, pTileMap)
{}

std::shared_ptr<int> BottomWall::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(10);
}
