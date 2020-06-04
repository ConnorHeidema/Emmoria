#ifndef DATABASE_READER_HPP
#define DATABASE_READER_HPP

#include "entity/EntityContainer.hpp"

#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>

#include <SFML/Graphics.hpp>

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
	 * Upon loading a new region this function maps all the gridabble objects into the tilemap
	 * @param entityContainer The entity container to get the griddables from
	 * @param tilemapName The tilemap filename to set to map the griddables to
	 */
	void MapGriddablesToTilemap_(
		EntityContainer& entityContainer,
		std::string const& tilemapName);

	LoggerType_t const mk_type;
	mongocxx::instance const mk_inst;
	mongocxx::client const mk_clientConnection;
	char const * const mk_databaseName;
};

#endif
