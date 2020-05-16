/**
 * The gameloop class is sort of the manager of the program
 * it continuously keeps the game running
 */

#ifndef GAME_LOOP_HPP
#define GAME_LOOP_HPP

#include "../../inc/util/logger/ILogger.hpp"

class GameLoop
{
public:
	/**
	 * Constructor to make testing indirection easier in the future of the start method
	 */
	GameLoop();

	/**
	 * Begins running the loop
	 */
	bool Start();

private:
	LoggerType_t const mk_type;

	unsigned int const mk_uScreenHeight;
	unsigned int const mk_uScreenWidth;
	unsigned int const mk_uFrameRate;
	char const * const mk_windowName;
	char const * const mk_collection;
	char const * const mk_subcollection;
};

#endif
