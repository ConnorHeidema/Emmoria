#include "entity/simple/Sign.hpp"

Sign::Sign(
	int x,
	int y,
	std::shared_ptr<TileMap> pTileMap,
	bsoncxx::array::element element)
		: IGriddedIInteractable(x, y, pTileMap)
{}

std::shared_ptr<int> Sign::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(13);
}
