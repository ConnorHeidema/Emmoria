#ifndef ENTITY_CONTAINER_HPP
#define ENTITY_CONTAINER_HPP

#include "entity/DrawableTransformable.hpp"
#include "entity/IUpdatable.hpp"
#include "entity/IInteractable.hpp"
#include "entity/IGridded.hpp"
#include "entity/EntityCombination.hpp"
#include "map/TileMap.hpp"

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

	EntityContainer(sf::Vector2u tileUnitSize, unsigned int tileWidth, unsigned int tileHeight)
		: m_pTileMap(std::make_shared<TileMap>(tileUnitSize, tileWidth, tileHeight)) {}

	std::shared_ptr<TileMap> m_pTileMap;

	std::list<std::shared_ptr<DrawableTransformable>> GetDrawableTransformableEntities();
	std::list<std::shared_ptr<IGridded>> GetGriddedEntities();
	std::list<std::shared_ptr<IInteractable>> GetInteractableEntities();
	std::list<std::shared_ptr<IUpdatable>> GetUpdatableEntities();

	#define REMOVE(entity) void Remove##entity##Entity(std::shared_ptr<entity>)
		REMOVE(DrawableTransformable);
		REMOVE(IGridded);
		REMOVE(IInteractable);
		REMOVE(IUpdatable);
	#undef REMOVE

	#define INSERT(entity) void Insert##entity##Entity(std::shared_ptr<entity>)
		INSERT(DrawableTransformable);
		INSERT(IGridded);
		INSERT(IInteractable);
		INSERT(IUpdatable);
	#undef INSERT

	#define INSERT(interface1, interface2) void Insert##interface1##interface2##Entity(std::shared_ptr<interface1##interface2>)
		INSERT(DrawableTransformable, IGridded);
		INSERT(DrawableTransformable, IInteractable);
		INSERT(DrawableTransformable, IUpdatable);
		INSERT(IGridded, IInteractable);
		INSERT(IGridded, IUpdatable);
		INSERT(IInteractable, IUpdatable);
	#undef INSERT

	#define INSERT(interface1, interface2, interface3) \
		void Insert##interface1##interface2##interface3##Entity(std::shared_ptr<interface1##interface2##interface3>)
		INSERT(DrawableTransformable, IGridded, IInteractable);
		INSERT(DrawableTransformable, IGridded, IUpdatable);
		INSERT(DrawableTransformable, IInteractable, IUpdatable);
		INSERT(IGridded, IInteractable, IUpdatable);
	#undef INSERT

private:
	std::list<std::shared_ptr<DrawableTransformable>> m_entityDrawableTransformableList;
	std::list<std::shared_ptr<IGridded>> m_entityIGriddedList;
	std::list<std::shared_ptr<IInteractable>> m_entityIInteractableList;
	std::list<std::shared_ptr<IUpdatable>> m_entityIUpdatableList;
};

#endif
