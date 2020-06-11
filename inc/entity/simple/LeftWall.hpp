#ifndef LEFT_WALL_HPP
#define LEFT_WALL_HPP

#include "entity/IGridded.hpp"

/**
 * The class represent a wall at the left of the screen
 * one can walk to the right of it but not to the right from the left
 */
class LeftWall
	: public IGridded
{
public:
	LeftWall(
		std::shared_ptr<SharedParameters> pSharedParameters,
		std::shared_ptr<TileMap> pTileMap,
		bsoncxx::array::element element);

	std::shared_ptr<int> GetSubTextureIndexPtr() override;
};

#endif
