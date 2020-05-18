#ifndef CORNER_HPP
#define CORNER_HPP

#include "../../../../inc/entity/interactable/IInteractableEntity.hpp"

/**
 * The class represents a corner which cannot be traversed
 */
class Corner
	: public IInteractableEntity
{
public:
	std::shared_ptr<int> GetSubTextureIndexPtr() override;
};

#endif
