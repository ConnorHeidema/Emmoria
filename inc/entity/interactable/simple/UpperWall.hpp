#ifndef UPPER_WALL_HPP
#define UPPER_WALL_HPP

#include "../../../../inc/entity/interactable/IInteractableEntity.hpp"

/**
 * The class represent a patch of grass and its interactable properties
 */
class UpperWall
	: public IInteractableEntity
{
public:
	std::shared_ptr<int> GetSubTextureIndexPtr() override;
private:
};

#endif
