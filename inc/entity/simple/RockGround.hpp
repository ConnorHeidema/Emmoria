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
	std::shared_ptr<int> GetSubTextureIndexPtr() override;
};

#endif
