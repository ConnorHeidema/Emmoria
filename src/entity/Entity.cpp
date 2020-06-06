#include "entity/Entity.hpp"

Entity::Entity() {};
Entity::~Entity() {};
bool Entity::ShouldBeDeleted()
{
	return true;
}
