#include "entity/simple/BottomWall.hpp"

BottomWall::BottomWall(
	int x,
	int y,
	std::shared_ptr<TileMap> pTileMap,
	bsoncxx::array::element element)
		: IGridded(x, y, pTileMap)
{}

std::shared_ptr<int> BottomWall::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(10);
}
