#ifndef BOTTOM_WALL_HPP
#define BOTTOM_WALL_HPP

#include "../../../../inc/entity/interactable/IInteractableEntity.hpp"

/**
 * The class represent a patch of grass and its interactable properties
 */
class BottomWall
	: public IInteractableEntity
{
public:
	std::shared_ptr<int> GetSubTextureIndexPtr() override;
private:
};

#endif
