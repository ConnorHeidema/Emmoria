#ifndef CORNER_HPP
#define CORNER_HPP

#include "../../../inc/entity/IGridded.hpp"

/**
 * The class represents a corner which cannot be traversed
 */
class Corner
	: public IGridded
{
public:
	std::shared_ptr<int> GetSubTextureIndexPtr() override;
};

#endif
