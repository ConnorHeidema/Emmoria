/**
 * The databasereader interfaces with mongodb when necessary
 * in order to aggregate different forms of objects
 * these objects are all the drawable objects,
 * and all the interactable objects
 */

#ifndef DATABASE_READER_HPP
#define DATABASE_READER_HPP

#include "../../inc/util/logger/ILogger.hpp"

#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>

#include <SFML/Graphics.hpp>

#include <list>

using Region = std::pair<int, int>;
using Position = std::pair<int, int>;

class DatabaseReader
{
public:
	/**
	 * Constructor
	 * @param databaseUrl The url of the database
	 * @param port The port of the database
	 */
	DatabaseReader(
		char const * const databaseUrl,
		short const port);

	/**
	 * When a new region needs to be loaded, this will load it in
	 */
	void LoadNewRegion();

	/**
	 * Returns a list of all the things
	 * that need to be drawn to the screen
	 */
	std::list<sf::Drawable> GetDrawables();

private:
	LoggerType_t const mk_type;
	mongocxx::instance const mk_inst;
	mongocxx::client const mk_clientConnection;
};

#endif
