#include "entity/simple/RightWall.hpp"

RightWall::RightWall(
	int x,
	int y,
	std::shared_ptr<TileMap> pTileMap,
	bsoncxx::array::element element)
		: IGridded(x, y, pTileMap)
{}

std::shared_ptr<int> RightWall::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(9);
}
