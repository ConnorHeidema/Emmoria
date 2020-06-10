#include "entity/simple/RockGround.hpp"

RockGround::RockGround(
	int x,
	int y,
	std::shared_ptr<TileMap> pTileMap,
	bsoncxx::array::element element)
		: IGridded(x, y, pTileMap)
{}

std::shared_ptr<int> RockGround::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(7);
}
