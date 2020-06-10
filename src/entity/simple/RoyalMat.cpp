#include "entity/simple/RoyalMat.hpp"

RoyalMat::RoyalMat(
	int x,
	int y,
	std::shared_ptr<TileMap> pTileMap,
	bsoncxx::array::element element)
		: IGridded(x, y, pTileMap)
{}

std::shared_ptr<int> RoyalMat::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(4);
}
