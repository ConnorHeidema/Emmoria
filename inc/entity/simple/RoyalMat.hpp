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
	RoyalMat(
		std::shared_ptr<SharedParameters> pSharedParameters,
		std::shared_ptr<TileMap> pTileMap,
		bsoncxx::array::element element);

	std::shared_ptr<int> GetSubTextureIndexPtr() override;
};

#endif
