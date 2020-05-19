#ifndef ENTITY_CONTAINER_HPP
#define ENTITY_CONTAINER_HPP

#include "../../inc/entity/DrawableTransformable.hpp"
#include "../../inc/entity/IUpdatable.hpp"
#include "../../inc/entity/IInteractable.hpp"

#include <list>
#include <memory>

/**
 * The entity container holds all the entities loaded in the scene
 * this includes all the drawable entities, updatable entities and
 * interactable entities
 */
class EntityContainer
{
public:
	std::list<std::shared_ptr<DrawableTransformable>> GetDrawableTransformableEntities();
	std::list<std::shared_ptr<IUpdatable>> GetUpdatableEntities();
	std::list<std::shared_ptr<IInteractable>> GetInteractableEntities();

	void RemoveDrawableTransformableEntity(std::shared_ptr<DrawableTransformable> drawableTransformableEntity);
	void RemoveUpdatableEntity(std::shared_ptr<IUpdatable> updatableEntity);
	void RemoveInteractableEntity(std::shared_ptr<IInteractable> interactableEntity);

	void InsertDrawableTransformableEntity(std::shared_ptr<DrawableTransformable> drawableTransformableEntity);
	void InsertUpdatableEntity(std::shared_ptr<IUpdatable> updatableEntity);
	void InsertInteractableEntity(std::shared_ptr<IInteractable> interactableEntity);
private:
	std::list<std::shared_ptr<DrawableTransformable>> m_drawableTransformableEntitiesList;
	std::list<std::shared_ptr<IUpdatable>> m_updatableEntitiesList;
	std::list<std::shared_ptr<IInteractable>> m_interactableEntitiesList;
};

#endif
