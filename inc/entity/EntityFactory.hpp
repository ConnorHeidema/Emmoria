#ifndef ENTITY_FACTORY_HPP
#define ENTITY_FACTORY_HPP

#include "entity/EntityContainer.hpp"

#include <bsoncxx/builder/stream/document.hpp>

#include <memory>
#include <string>

using Coordinate = std::pair<int, int>;

/**
 * The entity factory will load all the required entities into a container given an array of entities.
 */
class EntityFactory
{
public:

	/**
	 * From an element loads the element into the elements respective containers
	 */
	static void LoadEntityOntoContainer(
		bsoncxx::array::element element,
		std::shared_ptr<EntityContainer> entityContainer);
};

#endif
