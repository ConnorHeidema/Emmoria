#include "entity/simple/RoyalMat.hpp"

RoyalMat::RoyalMat(
	std::shared_ptr<SharedParameters> pSharedParameters,
	std::shared_ptr<TileMap> pTileMap,
	bsoncxx::array::element element)
		: IGridded(pSharedParameters, pTileMap)
{}

std::shared_ptr<int> RoyalMat::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(4);
}
