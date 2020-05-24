#ifndef ROYAL_MAT_HPP
#define ROYAL_MAT_HPP

#include "../../../inc/entity/IGridded.hpp"

/**
 * This class represents a mat which is at the start of the game
 */
class RoyalMat
	: public IGridded
{
public:
	std::shared_ptr<int> GetSubTextureIndexPtr() override;
};

#endif
