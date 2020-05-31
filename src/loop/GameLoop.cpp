#include "loop/GameLoop.hpp"
#include "util/logger/Logger.hpp"
#include "entity/DrawableTransformable.hpp"

GameLoop::GameLoop()
	: mk_type("GameLoop")
	, m_pLocation(std::make_shared<Location>(std::pair<int, int>(0, 0)))
	, mk_uScreenWidth(sf::VideoMode::getDesktopMode().width)
	, mk_uScreenHeight(sf::VideoMode::getDesktopMode().height)
	, mk_uFrameRate(60)
	, mk_windowName("Emmoria")
	//, mk_collection("files")
	//, mk_subcollection("")
	, mk_collection("map")
	, mk_subcollection("dawn_pillar")
	, mk_iconDir("image/logo/logo.png")
	, mk_screenReductionRatio(120)
	, m_entityContainer(
		sf::Vector2u(mk_screenReductionRatio, mk_screenReductionRatio),
		mk_uScreenWidth/mk_screenReductionRatio,
		mk_uScreenHeight/mk_screenReductionRatio)
	#ifdef DEBUG
		, m_debugMetricVisualizer()
	#endif
{ }

bool GameLoop::Start()
{
	s_pLogger->DebugLog(mk_type, "Gameloop started");

	auto pGameWindow = GetGameWindowPtr_();

	auto pDatabaseReader = GetDatabaseReaderPtr_();
	//pDatabaseReader->LoadFilesScreen(mk_collection, m_entityContainer);
	pDatabaseReader->LoadNewRegion(mk_collection, mk_subcollection, m_entityContainer);
	while (pGameWindow->isOpen()) { RunLoop_(pGameWindow, pDatabaseReader); }
	return true;
}

std::shared_ptr<sf::RenderWindow> GameLoop::GetGameWindowPtr_()
{
	auto pWindow(std::make_shared<sf::RenderWindow>
			(sf::VideoMode(mk_uScreenWidth, mk_uScreenHeight),
			mk_windowName,
			sf::Style::Fullscreen));
	pWindow->setFramerateLimit(mk_uFrameRate);
	SetIcon_(pWindow);
	return pWindow;
}

void GameLoop::SetIcon_(std::shared_ptr<sf::Window> pGameWindow)
{
	sf::Image icon;
	icon.loadFromFile(mk_iconDir);
	pGameWindow->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

std::shared_ptr<DatabaseReader> GameLoop::GetDatabaseReaderPtr_()
{
	auto pDatabaseReader(std::make_shared<DatabaseReader>(
		"emmoria",
		"mongodb://localhost",
		short(27017)));
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

void GameLoop::RunLoop_(
	std::shared_ptr<sf::RenderWindow> pGameWindow,
	std::shared_ptr<DatabaseReader> pDatabaseReader)
{
	m_pLocation->UpdateCurrentPosition();
	pGameWindow->clear();
	DrawAllEntities_(pGameWindow);
	UpdateAllEntities_();
	#ifdef DEBUG
		m_debugMetricVisualizer.Update();
		pGameWindow->draw(m_debugMetricVisualizer);
	#endif
	pGameWindow->display();
	CheckForEvents_(pGameWindow);
}

void GameLoop::UpdateAllEntities_()
{
	for (auto&& pEntity : m_entityContainer.GetUpdatableEntities())
	{
		pEntity->Update();
	}
}

void GameLoop::DrawAllEntities_(
	std::shared_ptr<sf::RenderWindow> pGameWindow)
{
	auto pair = m_pLocation->GetCurrentPosition();
	for (auto&& pEntity : m_entityContainer.GetDrawableTransformableEntities())
	{
		pEntity->setPosition(sf::Vector2f(-pair.first, -pair.second));
		pGameWindow->draw(*pEntity);
	}
}