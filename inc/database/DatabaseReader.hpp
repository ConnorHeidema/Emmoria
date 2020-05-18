#ifndef DATABASE_READER_HPP
#define DATABASE_READER_HPP

#include "../../inc/util/logger/ILogger.hpp"
#include "../../inc/map/TileMap.hpp"
#include "../../inc/entity/interactable/IInteractableEntity.hpp"

#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>

#include <bsoncxx/builder/stream/document.hpp>

#include <SFML/Graphics.hpp>

#include <memory>
#include <list>

using Region = std::pair<int, int>;
using Position = std::pair<int, int>;
using Range = std::pair<int, int>;

using bsoncxx::builder::stream::document;

/**
 * The databasereader interfaces with mongodb when necessary
 * in order to aggregate different forms of objects
 * these objects are all the drawable objects,
 * and all the interactable objects
 */
class DatabaseReader
{
public:
	/**
	 * Constructor
	 * @param databaseUrl The url of the database
	 * @param port The port of the database
	 */
	DatabaseReader(
		char const * const database,
		char const * const databaseUrl,
		short const port,
		sf::Vector2u const tileUnitSize,
		unsigned int const tileWidth,
		unsigned int const tileHeight);

	/**
	 * When a new region needs to be loaded, this will load it in
	 */
	void LoadNewRegion(
		char const * const collectionName,
		char const * const subCollectionName);

	/**
	 * Returns a list of all the things
	 * that need to be drawn to the screen
	 */
	std::list<std::shared_ptr<sf::Drawable>> GetDrawables();

private:

	/**
	 * Gets a region of objects from the mongodb
	 * @param collection The collection to grab the stream from
	 * @param keyX The x key
	 * @param rangeX The range of regions wanted in the x plane
	 * @param keyY The y key
	 * @param rangeY The range of regions wanted in the y plane
	 */
	mongocxx::cursor GetRegions_(
		mongocxx::collection& collection,
		std::string const& keyX,
		Range rangeX,
		std::string const& keyY,
		Range rangeY);

	/**
	 * Determines whether an entity should be loaded onto the tile map
	 * @param element The entity being inspected
	 * @return whether the entity should be loaded into the tile map
	 */
	bool ShouldDrawInArray_(bsoncxx::v_noabi::array::element element);


	/**
	 * Creates the query for only getting contrained regions over one dimension
	 * @param condition The condition modified to create this query
	 * @param key The key for the dimension
	 * @param range The range of regions wanted in the dimension
	 */
	void UpdateCondition1D_(
		document& condition /*in-out*/,
		std::string const key,
		Range range);

	/**
	 * Combines 2 conditions together
	 * @param combinedCondition The combined condition
	 * @param firstCondition The first condition to combine
	 * @param secondCondition The second condition to combine
	 */
	void CombineConditions_(
			document& combinedCondition /*in-out*/,
			document& firstCondition,
			document& secondCondition);

	LoggerType_t const mk_type;
	mongocxx::instance const mk_inst;
	mongocxx::client const mk_clientConnection;
	char const * const mk_databaseName;

	std::shared_ptr<TileMap> m_pBottomLayerTileMap;
	std::list<std::shared_ptr<IInteractableEntity>> interactableObjects;
	std::list<std::shared_ptr<sf::Drawable>> drawableObjects;
};

#endif
