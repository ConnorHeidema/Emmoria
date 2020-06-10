#include "entity/simple/Hole.hpp"


Hole::Hole(
	int x,
	int y,
	std::shared_ptr<TileMap> pTileMap,
	bsoncxx::array::element element)
		: IGriddedIInteractable(x, y, pTileMap)
{}

std::shared_ptr<int> Hole::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(11);
}
