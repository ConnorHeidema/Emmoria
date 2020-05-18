#ifndef BOTTOM_WALL_HPP
#define BOTTOM_WALL_HPP

#include "../../../../inc/entity/interactable/IInteractableEntity.hpp"

/**
 * The class represent a wall at the bottom of the screen
 * one can walk above it but not down and below it
 */
class BottomWall
	: public IInteractableEntity
{
public:
	std::shared_ptr<int> GetSubTextureIndexPtr() override;
};

#endif
