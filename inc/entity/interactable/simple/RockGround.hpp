#ifndef ROCK_GROUND_HPP
#define ROCK_GROUND_HPP

#include "../../../../inc/entity/interactable/IInteractableEntity.hpp"

/**
 * The class represents rock ground which you may walk on
 */
class RockGround
	: public IInteractableEntity
{
public:
	std::shared_ptr<int> GetSubTextureIndexPtr() override;
};

#endif
