#include "entity/simple/RightWall.hpp"

RightWall::RightWall(
	std::shared_ptr<SharedParameters> pSharedParameters,
	std::shared_ptr<TileMap> pTileMap,
	bsoncxx::array::element element)
		: IGridded(pSharedParameters, pTileMap)
{}

std::shared_ptr<int> RightWall::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(9);
}
