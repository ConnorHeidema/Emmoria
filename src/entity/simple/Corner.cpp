#include "entity/simple/Corner.hpp"

Corner::Corner(	std::shared_ptr<SharedParameters> pSharedParameters,
	std::shared_ptr<TileMap> pTileMap,
	bsoncxx::array::element element)
		: IGridded(pSharedParameters, pTileMap)
{}

std::shared_ptr<int> Corner::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(5);
}
