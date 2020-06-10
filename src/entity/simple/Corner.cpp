#include "entity/simple/Corner.hpp"

Corner::Corner(
	int x,
	int y,
	std::shared_ptr<TileMap> pTileMap,
	bsoncxx::array::element element)
		: IGridded(x, y, pTileMap)
{}

std::shared_ptr<int> Corner::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(5);
}
