#ifndef STAIR_HPP
#define STAIR_HPP

#include "entity/EntityCombination.hpp"

/**
 * The class represent a hole that the player may fall down
 */
class Stair
	: public IGriddedIInteractable
{
public:
	Stair(
		std::shared_ptr<SharedParameters> pSharedParameters,
		std::shared_ptr<TileMap> pTileMap,
		bsoncxx::array::element element);

	std::shared_ptr<int> GetSubTextureIndexPtr() override;
};

#endif
