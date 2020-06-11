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
	RockGround(
		std::shared_ptr<SharedParameters> pSharedParameters,
		std::shared_ptr<TileMap> pTileMap,
		bsoncxx::array::element element);

	std::shared_ptr<int> GetSubTextureIndexPtr() override;
};

#endif
