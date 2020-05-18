#ifndef GAME_LOOP_HPP
#define GAME_LOOP_HPP

#include "../../inc/util/logger/ILogger.hpp"
#include "../../inc/database/DatabaseReader.hpp"

#include <SFML/Graphics.hpp>

#include <memory>

/**
 * The gameloop class is sort of the manager of the program
 * it continuously keeps the game running
 */
class GameLoop
{
public:
	/**
	 * Constructor to make testing indirection easier in the future of the start method
	 */
	GameLoop();

	/**
	 * Begins running the loop
	 * @return Whether the gameloop finished successfully.
	 * 		   It shouldn't leave this loop until the
	 * 		   program is over.
	 */
	bool Start();

private:

	/**
	 * Gets a shared pointer to the gameWindow
	 * @return the window
	 */
	std::shared_ptr<sf::RenderWindow> GetGameWindowPtr_();

	/**
	 * Gets a shared pointer to the database reader.
	 * @return the databaseReader
	 */
	std::shared_ptr<DatabaseReader> GetDatabaseReaderPtr_();

	void CheckForEvents_(std::shared_ptr<sf::Window> pGameWindow);

	LoggerType_t const mk_type;

	unsigned int const mk_uScreenHeight;
	unsigned int const mk_uScreenWidth;
	unsigned int const mk_uFrameRate;
	char const * const mk_windowName;
	char const * const mk_collection;
	char const * const mk_subcollection;

	unsigned int const mk_screenReductionRatio;
};

#endif
