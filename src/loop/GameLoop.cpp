#include "../../inc/loop/GameLoop.hpp"
#include "../../inc/util/logger/Logger.hpp"

#include <SFML/Graphics.hpp>

GameLoop::GameLoop()
	: mk_type("GameLoop")
	, mk_uScreenHeight(sf::VideoMode::getDesktopMode().height)
	, mk_uScreenWidth(sf::VideoMode::getDesktopMode().width)
	, mk_uFrameRate(60)
	, mk_windowName("Emmoria")
	, mk_collection("map")
	, mk_subcollection("dawn_pillar")
{ }

bool GameLoop::Start()
{
	s_pLogger->DebugLog(mk_type, "Gameloop started");
	return true;
}