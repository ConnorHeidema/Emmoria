#ifndef BOTTOM_WALL_HPP
#define BOTTOM_WALL_HPP

#include "entity/IGridded.hpp"

/**
 * The class represent a wall at the bottom of the screen
 * one can walk above it but not down and below it
 */
class BottomWall
	: public IGridded
{
public:
	BottomWall(std::shared_ptr<SharedParameters> pSharedParameters, std::shared_ptr<TileMap> pTileMap,
		bsoncxx::array::element element);

	std::shared_ptr<int> GetSubTextureIndexPtr() override;
};

#endif
