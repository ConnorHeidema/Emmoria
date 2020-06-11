#ifndef GRASS_HPP
#define GRASS_HPP

#include "entity/EntityCombination.hpp"

#include <memory>

/**
 * The class represent a patch of grass and its interactable properties
 */
class Grass
	: public IGriddedIUpdatable
{
public:
	Grass(
		std::shared_ptr<SharedParameters> pSharedParameters,
		std::shared_ptr<TileMap> pTileMap,
		bsoncxx::array::element element);

	~Grass();

	Returnable Update() override;
	std::shared_ptr<int> GetSubTextureIndexPtr() override;
private:
	std::shared_ptr<int> m_ptmp;
	int m_currentFrame;
	int m_cyclicFrame;
	int m_numAnimations;
};

#endif
