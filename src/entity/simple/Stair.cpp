#include "entity/simple/Stair.hpp"

Stair::Stair(
	std::shared_ptr<SharedParameters> pSharedParameters,
	std::shared_ptr<TileMap> pTileMap,
	bsoncxx::array::element element)
		: IGriddedIInteractable(pSharedParameters, pTileMap)
{}

std::shared_ptr<int> Stair::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(12);
}
