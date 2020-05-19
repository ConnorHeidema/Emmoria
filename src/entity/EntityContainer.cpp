#include "../../inc/entity/EntityContainer.hpp"

std::list<std::shared_ptr<DrawableTransformable>> EntityContainer::GetDrawableTransformableEntities()
{
	return m_drawableTransformableEntitiesList;
}

std::list<std::shared_ptr<IUpdatable>> EntityContainer::GetUpdatableEntities()
{
	return m_updatableEntitiesList;
}

std::list<std::shared_ptr<IInteractable>> EntityContainer::GetInteractableEntities()
{
	return m_interactableEntitiesList;
}

void EntityContainer::RemoveDrawableTransformableEntity(std::shared_ptr<DrawableTransformable> drawableTransformableEntity)
{
	m_drawableTransformableEntitiesList.remove(drawableTransformableEntity);
}

void EntityContainer::RemoveUpdatableEntity(std::shared_ptr<IUpdatable> updatableEntity)
{
	m_updatableEntitiesList.remove(updatableEntity);
}

void EntityContainer::RemoveInteractableEntity(std::shared_ptr<IInteractable> interactableEntity)
{
	m_interactableEntitiesList.remove(interactableEntity);
}

void EntityContainer::InsertDrawableTransformableEntity(std::shared_ptr<DrawableTransformable> drawableTransformableEntity)
{
	m_drawableTransformableEntitiesList.emplace_front(drawableTransformableEntity);
}

void EntityContainer::InsertUpdatableEntity(std::shared_ptr<IUpdatable> updatableEntity)
{
	m_updatableEntitiesList.emplace_front(updatableEntity);
}

void EntityContainer::InsertInteractableEntity(std::shared_ptr<IInteractable> interactableEntity)
{
	m_interactableEntitiesList.emplace_front(interactableEntity);
}
