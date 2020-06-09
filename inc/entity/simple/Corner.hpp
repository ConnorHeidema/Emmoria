#ifndef CORNER_HPP
#define CORNER_HPP

#include "entity/IGridded.hpp"

/**
 * The class represents a corner which cannot be traversed
 */
class Corner
	: public IGridded
{
public:
	Corner(int x, int y, std::shared_ptr<TileMap> pTileMap,
		bsoncxx::array::element element);

	std::shared_ptr<int> GetSubTextureIndexPtr() override;
};

#endif
