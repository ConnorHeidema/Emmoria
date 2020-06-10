/**
 * This is the entry point of the game.
 */

#include "inc/util/logger/Logger.hpp"
#include "inc/loop/GameLoop.hpp"

int main (int, char**)
{
	auto type = LoggerType_t("main");
	s_pLogger->DebugLog(type, "Inside main, logger working");

	GameLoop gameLoop;

	gameLoop.Start() ?
		s_pLogger->DebugLog(type, "Game loop exited succesfully") :
		s_pLogger->WarningLog(type, "Game loop exited unsuccessfully, error occurred");

	return 0;
}
