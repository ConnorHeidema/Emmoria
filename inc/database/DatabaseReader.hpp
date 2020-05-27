#ifndef DATABASE_READER_HPP
#define DATABASE_READER_HPP

#include "../../inc/util/logger/ILogger.hpp"
#include "../../inc/map/TileMap.hpp"
#include "../../inc/entity/IGridded.hpp"
#include "../../inc/entity/DrawableTransformable.hpp"
#include "../../inc/entity/EntityContainer.hpp"

#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>

#include <bsoncxx/builder/stream/document.hpp>

#include <SFML/Graphics.hpp>

#include <memory>
#include <list>

using Range = std::pair<int, int>;

using bsoncxx::builder::stream::document;

/**
 * The databasereader interfaces with mongodb when necessary
 * in order to aggregate different regions of objects
 */
class DatabaseReader
{
public:

	/**
	 * Constructor
	 * @param database The name of the database to connect to
	 * @param databaseUrl The url of the database
	 * @param port The port of the database
	 */
	DatabaseReader(
		char const * const database,
		char const * const databaseUrl,
		short const port);

	/**
	 * When a new region needs to be loaded, this will load it in
	 * @param collectionName The name of the collection being loaded
	 * @param subCollectionName The name of the subcollection being loaded
	 * @param entityContainer A reference to the entity container that will be filled
	 * 						  with the appropriate lists of containers
	 */
	void LoadNewRegion(
		char const * const collectionName,
		char const * const subCollectionName,
		EntityContainer& entityContainer);

private:

	/**
	 * Gets a region of objects from the mongodb
	 * @param collection The collection to grab the stream from
	 * @param keyX The x key
	 * @param rangeX The range of regions wanted in the x plane
	 * @param keyY The y key
	 * @param rangeY The range of regions wanted in the y plane
	 * @return A cursor to the list of documents that match the criteria
	 */
	mongocxx::cursor GetRegions_(
		mongocxx::collection& collection,
		std::string const& keyX,
		Range const& rangeX,
		std::string const& keyY,
		Range const& rangeY);

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
		std::string const& key,
		Range const& range);

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
};

#endif
