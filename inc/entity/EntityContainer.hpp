#ifndef ENTITY_CONTAINER_HPP
#define ENTITY_CONTAINER_HPP

#include "entity/EntityCombination.hpp"

#include "util/datastructure/QuadTree.hpp"

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

	EntityContainer(TextureContainer& textureContainer, sf::Vector2u tileUnitSize, unsigned int tileWidth, unsigned int tileHeight);

	TextureContainer& m_textureContainer;
	std::shared_ptr<TileMap> m_pTileMap;

	std::list<std::shared_ptr<DrawableTransformable>> GetDrawableTransformableEntities();
	std::list<std::shared_ptr<IGridded>> GetGriddedEntities();
	std::list<std::shared_ptr<QuadNode>> GetInteractableEntities(); // In a world with enough time or if I wanted to include boost, this would
																		 // would be a quad map instead of a list. Someday it likely will need to be
																		 // a quad map for significant performance gains
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

	void ClearAllEntities();

	QuadTree m_entityIInteractableList;
private:
	std::list<std::shared_ptr<DrawableTransformable>> m_entityDrawableTransformableList;
	std::list<std::shared_ptr<IGridded>> m_entityIGriddedList;
	std::list<std::shared_ptr<IUpdatable>> m_entityIUpdatableList;

};

#endif
