#ifndef HOLE_HPP
#define HOLE_HPP

#include "entity/EntityCombination.hpp"

/**
 * The class represent a hole that the player may fall down
 */
class Hole
	: public IGriddedIInteractable
{
public:
	Hole(
		int x,
		int y,
		std::shared_ptr<TileMap> pTileMap,
		bsoncxx::array::element element);

	std::shared_ptr<int> GetSubTextureIndexPtr() override;
};

#endif
