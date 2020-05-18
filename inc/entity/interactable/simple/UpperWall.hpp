#ifndef UPPER_WALL_HPP
#define UPPER_WALL_HPP

#include "../../../../inc/entity/interactable/IInteractableEntity.hpp"

/**
 * This class represents a wall at the top of the screen.
 */
class UpperWall
	: public IInteractableEntity
{
public:
	std::shared_ptr<int> GetSubTextureIndexPtr() override;
};

#endif
