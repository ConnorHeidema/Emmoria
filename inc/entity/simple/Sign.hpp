#ifndef SIGN_HPP
#define SIGN_HPP

#include "entity/EntityCombination.hpp"

/**
 * The class represent a sign that the player may read
 */
class Sign
	: public IGriddedIInteractable
{
public:
	Sign(
		std::shared_ptr<SharedParameters> pSharedParameters,
		std::shared_ptr<TileMap> pTileMap,
		bsoncxx::array::element element);

	std::shared_ptr<int> GetSubTextureIndexPtr() override;
};

#endif
