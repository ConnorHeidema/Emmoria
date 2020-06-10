#ifndef UPPER_WALL_HPP
#define UPPER_WALL_HPP

#include "entity/IGridded.hpp"

/**
 * This class represents a wall at the top of the screen.
 */
class UpperWall
	: public IGridded
{
public:
	UpperWall(
		int x,
		int y,
		std::shared_ptr<TileMap> pTileMap,
		bsoncxx::array::element element);

	std::shared_ptr<int> GetSubTextureIndexPtr() override;
};

#endif
