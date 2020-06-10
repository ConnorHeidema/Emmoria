#include "entity/simple/LeftWall.hpp"

LeftWall::LeftWall(
	int x,
	int y,
	std::shared_ptr<TileMap> pTileMap,
	bsoncxx::array::element element)
		: IGridded(x, y, pTileMap)
{}

std::shared_ptr<int> LeftWall::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(6);
}
