#ifndef GRASS_HPP
#define GRASS_HPP

#include "../../../inc/entity/EntityCombination.hpp"

#include <memory>

/**
 * The class represent a patch of grass and its interactable properties
 */
class Grass
	: public IGriddedIUpdatable
{
public:
	Grass(int x, int y) : IGriddedIUpdatable(x, y), p_tmp(std::make_shared<int>(0)) {}
	void Update() override;
	std::shared_ptr<int> GetSubTextureIndexPtr() override;
	virtual ~Grass() {};
	std::shared_ptr<int> p_tmp;
};

#endif
