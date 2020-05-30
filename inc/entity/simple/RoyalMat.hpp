#ifndef ROYAL_MAT_HPP
#define ROYAL_MAT_HPP

#include "entity/IGridded.hpp"

/**
 * This class represents a mat which is at the start of the game
 */
class RoyalMat
	: public IGridded
{
public:
	RoyalMat(int x, int y) : IGridded(x, y) {}
	std::shared_ptr<int> GetSubTextureIndexPtr() override;
};

#endif
