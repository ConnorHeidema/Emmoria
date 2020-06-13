#include "entity/EntityContainer.hpp"

EntityContainer::EntityContainer(TextureContainer& textureContainer, sf::Vector2u tileUnitSize, unsigned int tileWidth, unsigned int tileHeight)
	: m_textureContainer(textureContainer)
	, m_pTileMap(std::make_shared<TileMap>(tileUnitSize, tileWidth, tileHeight, textureContainer))
	, m_entityIInteractableList(0, 0, 1920, 1080)
{}

std::list<std::shared_ptr<DrawableTransformable>> EntityContainer::GetDrawableTransformableEntities()
{
	return m_entityDrawableTransformableList;
}

std::list<std::shared_ptr<IGridded>> EntityContainer::GetGriddedEntities()
{
	return m_entityIGriddedList;
}

std::list<std::shared_ptr<QuadNode>> EntityContainer::GetInteractableEntities()
{
	return m_entityIInteractableList.RetrieveAll();
}

std::list<std::shared_ptr<IUpdatable>> EntityContainer::GetUpdatableEntities()
{
	return m_entityIUpdatableList;
}

void EntityContainer::RemoveDrawableTransformableEntity(std::shared_ptr<DrawableTransformable> drawableTransformableEntity)
{
	m_entityDrawableTransformableList.remove(drawableTransformableEntity);
}

void EntityContainer::RemoveIGriddedEntity(std::shared_ptr<IGridded> griddedEntity)
{
	m_entityIGriddedList.remove(griddedEntity);
}

void EntityContainer::RemoveIInteractableEntity(std::shared_ptr<IInteractable> interactableEntity)
{
	m_entityIInteractableList.Remove(interactableEntity->m_id);
}

void EntityContainer::RemoveIUpdatableEntity(std::shared_ptr<IUpdatable> updatableEntity)
{
	m_entityIUpdatableList.remove(updatableEntity);
}

void EntityContainer::InsertDrawableTransformableEntity(std::shared_ptr<DrawableTransformable> drawableTransformableEntity)
{
	m_entityDrawableTransformableList.emplace_front(drawableTransformableEntity);
}

void EntityContainer::InsertIGriddedEntity(std::shared_ptr<IGridded> griddedEntity)
{
	m_entityIGriddedList.emplace_front(griddedEntity);
}

void EntityContainer::InsertIInteractableEntity(std::shared_ptr<IInteractable> interactableEntity)
{
	m_entityIInteractableList.emplace_front(interactableEntity);
}

void EntityContainer::InsertIUpdatableEntity(std::shared_ptr<IUpdatable> updatableEntity)
{
	m_entityIUpdatableList.emplace_front(updatableEntity);
}

#define INSERT(interface1, interface2) \
	void EntityContainer::Insert##interface1##interface2##Entity(std::shared_ptr<interface1##interface2> entity) \
	{ \
		m_entity##interface1##List.emplace_front(entity); \
		m_entity##interface2##List.emplace_front(entity); \
	}
	INSERT(DrawableTransformable, IGridded)
	INSERT(DrawableTransformable, IInteractable)
	INSERT(DrawableTransformable, IUpdatable)
	INSERT(IGridded, IInteractable)
	INSERT(IGridded, IUpdatable)
	INSERT(IInteractable, IUpdatable)

#undef INSERT

#define INSERT(interface1, interface2, interface3) \
	void EntityContainer::Insert##interface1##interface2##interface3##Entity(std::shared_ptr<interface1##interface2##interface3> entity) \
	{ \
		m_entity##interface1##List.emplace_front(entity); \
		m_entity##interface2##List.emplace_front(entity); \
		m_entity##interface3##List.emplace_front(entity); \
	}

	INSERT(DrawableTransformable, IGridded, IInteractable)
	INSERT(DrawableTransformable, IGridded, IUpdatable)
	INSERT(DrawableTransformable, IInteractable, IUpdatable)
	INSERT(IGridded, IInteractable, IUpdatable)

#undef INSERT

void EntityContainer::ClearAllEntities()
{
	m_entityDrawableTransformableList.clear();
	m_entityIGriddedList.clear();
	m_entityIInteractableList.Clear();
	m_entityIUpdatableList.clear();
}
