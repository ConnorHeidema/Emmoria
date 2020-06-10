#include "entity/simple/Stair.hpp"

Stair::Stair(
	int x,
	int y,
	std::shared_ptr<TileMap> pTileMap,
	bsoncxx::array::element element)
		: IGriddedIInteractable(x, y, pTileMap)
{}

std::shared_ptr<int> Stair::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(12);
}
