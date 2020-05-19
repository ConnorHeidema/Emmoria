#ifndef GRASS_HPP
#define GRASS_HPP

#include "../../../inc/entity/IGridded.hpp"

/**
 * The class represent a patch of grass and its interactable properties
 */
class Grass
	: public IGridded
{
public:
	std::shared_ptr<int> GetSubTextureIndexPtr() override;
};

#endif
