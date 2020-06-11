#include "entity/simple/Sign.hpp"

Sign::Sign(
	std::shared_ptr<SharedParameters> pSharedParameters,
	std::shared_ptr<TileMap> pTileMap,
	bsoncxx::array::element element)
		: IGriddedIInteractable(pSharedParameters, pTileMap)
{}

std::shared_ptr<int> Sign::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(13);
}
