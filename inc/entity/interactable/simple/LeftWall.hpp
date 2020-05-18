#ifndef LEFT_WALL_HPP
#define LEFT_WALL_HPP

#include "../../../../inc/entity/interactable/IInteractableEntity.hpp"

/**
 * The class represent a patch of grass and its interactable properties
 */
class LeftWall
	: public IInteractableEntity
{
public:
	std::shared_ptr<int> GetSubTextureIndexPtr() override;
private:
};

#endif
