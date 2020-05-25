#ifndef ROCK_GROUND_HPP
#define ROCK_GROUND_HPP

#include "../../../inc/entity/IGridded.hpp"

/**
 * The class represents rock ground which you may walk on
 */
class RockGround
	: public IGridded
{
public:
	RockGround(int x, int y) : IGridded(x, y) {}
	std::shared_ptr<int> GetSubTextureIndexPtr() override;
};

#endif
