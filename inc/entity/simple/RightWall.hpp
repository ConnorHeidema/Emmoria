#ifndef RIGHT_WALL_HPP
#define RIGHT_WALL_HPP

#include "../../../inc/entity/IGridded.hpp"

/**
 * The class represent a wall at the right of the screen
 * one can walk to the left of it but not to the right of it
 */
class RightWall
	: public IGridded
{
public:
	RightWall(int x, int y) : IGridded(x, y) {}
	std::shared_ptr<int> GetSubTextureIndexPtr() override;
};

#endif
