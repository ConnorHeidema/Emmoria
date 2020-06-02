#ifndef ENTITY_FACTORY_HPP
#define ENTITY_FACTORY_HPP

#include "map/TileMap.hpp"
#include "entity/IGridded.hpp"
#include "entity/EntityContainer.hpp"

#include <bsoncxx/builder/stream/document.hpp>

#include <memory>
#include <string>

using Coordinate = std::pair<int, int>;

class EntityFactory
{
public:

	static void LoadEntityOntoContainer(
		bsoncxx::array::element element,
		EntityContainer& entityContainer);

	static void MapGriddablesToTilemap(
		EntityContainer& entityContainer,
		std::string tilemapName);

private:

	/**
	 * Gets the coordinate that the entity should be
	 * @param element The element that the index may be found
	 * @return The coordinate.
	 */
	static Coordinate GetCoordinate_(bsoncxx::array::element element);


	static Coordinate GetLocation_(bsoncxx::array::element element);

	/**
	 * Gets the name of the entity
	 * @param element The element the name can be found from
	 * @return The name.
	 */
	static std::string GetStringName_(bsoncxx::array::element element);
};

#endif
