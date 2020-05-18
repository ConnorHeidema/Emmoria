#ifndef LEFT_WALL_HPP
#define LEFT_WALL_HPP

#include "../../../../inc/entity/interactable/IInteractableEntity.hpp"

/**
 * The class represent a wall at the left of the screen
 * one can walk to the right of it but not to the right from the left
 */
class LeftWall
	: public IInteractableEntity
{
public:
	std::shared_ptr<int> GetSubTextureIndexPtr() override;
};

#endif
