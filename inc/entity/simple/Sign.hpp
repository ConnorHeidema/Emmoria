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
	Sign(int x, int y, std::shared_ptr<TileMap> pTileMap,
		bsoncxx::array::element element) : IGriddedIInteractable(x, y, pTileMap) {}
	std::shared_ptr<int> GetSubTextureIndexPtr() override;
};

#endif