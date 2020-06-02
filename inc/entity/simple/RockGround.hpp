#ifndef ROCK_GROUND_HPP
#define ROCK_GROUND_HPP

#include "entity/IGridded.hpp"

/**
 * The class represents rock ground which you may walk on
 */
class RockGround
	: public IGridded
{
public:
	RockGround(int x, int y, std::shared_ptr<TileMap> pTileMap,
		bsoncxx::array::element element) : IGridded(x, y, pTileMap) {}
	std::shared_ptr<int> GetSubTextureIndexPtr() override;
};

#endif
