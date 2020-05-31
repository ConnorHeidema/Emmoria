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
	Stair(int x, int y, std::shared_ptr<TileMap> pTileMap) : IGriddedIInteractable(x, y, pTileMap) {}
	std::shared_ptr<int> GetSubTextureIndexPtr() override;
};

#endif
