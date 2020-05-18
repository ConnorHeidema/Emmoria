#ifndef CORNER_HPP
#define CORNER_HPP

#include "../../../../inc/entity/interactable/IInteractableEntity.hpp"

/**
 * The class represent a patch of grass and its interactable properties
 */
class Corner
	: public IInteractableEntity
{
public:
	std::shared_ptr<int> GetSubTextureIndexPtr() override;
private:
};

#endif
