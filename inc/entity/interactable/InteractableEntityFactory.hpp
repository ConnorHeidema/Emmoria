#ifndef INTERACTABLE_ENTITY_FACTORY_HPP
#define INTERACTABLE_ENTITY_FACTORY_HPP

#include "../../../inc/map/TileMap.hpp"
#include "../../../inc/entity/interactable/IInteractableEntity.hpp"

#include <bsoncxx/builder/stream/document.hpp>

#include <memory>
#include <string>

using Coordinate = std::pair<int, int>;

class InteractableEntityFactory
{
public:
	/**
	 * Creates and sets an interactable entity from a found and checked element
	 * @param element The element with the entity information
	 * @param pBottomLayerTileMap The tilemap which the entity will be created on.
	 */
	static std::shared_ptr<IInteractableEntity> CreateInteractableEntity(
		bsoncxx::array::element element,
		std::shared_ptr<TileMap> pBottomLayerTileMap);
private:

	/**
	 * Gets the coordinate that the entity should be
	 * @param element The element that the index may be found
	 * @return The coordinate.
	 */
	static Coordinate GetCoordinate_(bsoncxx::array::element element);

	/**
	 * Gets the name of the entity
	 * @param element The element the name can be found from
	 * @return The name.
	 */
	static std::string GetStringName_(bsoncxx::array::element element);

	/**
	 * Gets the interactable entity from the name
	 * @param stringName The name of the entiyt
	 * @return the interactable entity
	 */
	static std::shared_ptr<IInteractableEntity> GetInteractableEntity_(
		std::string const& stringName);

	/**
	 * Returns an entity if no other interactable entity can be found.
	 */
	static std::shared_ptr<IInteractableEntity> GetDefaultInteractableEntity_();
};

#endif
