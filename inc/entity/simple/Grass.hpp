#ifndef GRASS_HPP
#define GRASS_HPP

#include "../../../inc/entity/EntityCombination.hpp"

/**
 * The class represent a patch of grass and its interactable properties
 */
class Grass
	: public IGriddedIUpdatable
{
public:
	Grass(int x, int y) : IGriddedIUpdatable(x, y) {}
	std::shared_ptr<int> GetSubTextureIndexPtr() override;
	virtual ~Grass() {};
};

#endif
