#include "entity/simple/Hole.hpp"


Hole::Hole(
	std::shared_ptr<SharedParameters> pSharedParameters,
	std::shared_ptr<TileMap> pTileMap,
	bsoncxx::array::element element)
		: IGriddedIInteractable(pSharedParameters, pTileMap)
{}

std::shared_ptr<int> Hole::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(11);
}
