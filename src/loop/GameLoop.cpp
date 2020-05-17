#include "../../inc/loop/GameLoop.hpp"
#include "../../inc/util/logger/Logger.hpp"
#include "../../inc/database/DatabaseReader.hpp"
#include "../../inc/debug/DebugMetricVisualizer.hpp"

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
	auto pGameWindow = GetGameWindow_();
	DatabaseReader databaseReader(
		"emmoria",
		"mongodb://localhost",
		short(27017));
	databaseReader.LoadNewRegion("map", "dawn_pillar");
	return true;
}

std::shared_ptr<sf::RenderWindow> GameLoop::GetGameWindow_()
{
	auto pWindow(std::make_shared<sf::RenderWindow>
			(sf::VideoMode(mk_uScreenWidth, mk_uScreenHeight),
			mk_windowName,
			sf::Style::Fullscreen));
	pWindow->setFramerateLimit(mk_uFrameRate);
	return pWindow;
}