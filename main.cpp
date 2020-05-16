/**
 * This is the entry point of the game.
 */

#include "inc/util/logger/Logger.hpp"

int main (int, char**)
{
	auto type = LoggerType_t("main");
	s_pLogger->DebugLog(type, "Inside main");
	return 0;
}
