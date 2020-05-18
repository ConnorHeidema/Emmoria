#include "../../inc/loop/GameLoop.hpp"
#include "../../inc/util/logger/Logger.hpp"
#include "../../inc/debug/DebugMetricVisualizer.hpp"

GameLoop::GameLoop()
	: mk_type("GameLoop")
	, mk_uScreenHeight(sf::VideoMode::getDesktopMode().height)
	, mk_uScreenWidth(sf::VideoMode::getDesktopMode().width)
	, mk_uFrameRate(60)
	, mk_windowName("Emmoria")
	, mk_collection("map")
	, mk_subcollection("dawn_pillar")
	, mk_screenReductionRatio(120)
{ }

bool GameLoop::Start()
{
	s_pLogger->DebugLog(mk_type, "Gameloop started");
	auto pGameWindow = GetGameWindowPtr_();
	auto pDatabaseReader = GetDatabaseReaderPtr_();
	pDatabaseReader->LoadNewRegion(mk_collection, mk_subcollection);

	while (pGameWindow->isOpen())
	{
		pGameWindow->clear();
		for (auto pEntity : pDatabaseReader->GetDrawables())
		{
			pGameWindow->draw(*pEntity);
		}
		pGameWindow->display();

		CheckForEvents_(pGameWindow);
    }
	return true;
}

std::shared_ptr<sf::RenderWindow> GameLoop::GetGameWindowPtr_()
{
	auto pWindow(std::make_shared<sf::RenderWindow>
			(sf::VideoMode(mk_uScreenWidth, mk_uScreenHeight),
			mk_windowName,
			sf::Style::Fullscreen));
	pWindow->setFramerateLimit(mk_uFrameRate);
	return pWindow;
}

std::shared_ptr<DatabaseReader> GameLoop::GetDatabaseReaderPtr_()
{

	auto pDatabaseReader(std::make_shared<DatabaseReader>(
		"emmoria",
		"mongodb://localhost",
		short(27017),
		sf::Vector2u(mk_screenReductionRatio, mk_screenReductionRatio),
		mk_uScreenWidth/mk_screenReductionRatio,
		mk_uScreenHeight/mk_screenReductionRatio));
	return pDatabaseReader;
}

void GameLoop::CheckForEvents_(std::shared_ptr<sf::Window> pGameWindow)
{
	sf::Event event;
	while (pGameWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			pGameWindow->close();
		}
		else if(event.type == sf::Event::GainedFocus)
		{
			s_pLogger->DebugLog(mk_type, "Window Gained Focus");
		}
		else if(event.type == sf::Event::LostFocus)
		{
			s_pLogger->DebugLog(mk_type, "Window Lost Focus");
		}
	}
}