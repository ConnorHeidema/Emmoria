#include "../../inc/loop/GameLoop.hpp"
#include "../../inc/util/logger/Logger.hpp"

GameLoop::GameLoop()
	: m_type("GameLoop")
{}

bool GameLoop::Start()
{
	s_pLogger->DebugLog(m_type, "Gameloop started");
	return true;
}