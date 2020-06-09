#include "loop/GameLoop.hpp"

#include "util/logger/Logger.hpp"

unsigned int GameLoop::ms_uScreenWidth = 0;
unsigned int GameLoop::ms_uScreenHeight = 0;
unsigned int GameLoop::ms_screenReductionRatio = 120;


GameLoop::GameLoop()
	: mk_type("GameLoop")
	, m_pLocation(std::make_shared<Location>(std::pair<int, int>(0, 0)))
	, mk_uFrameRate(60)
	, mk_windowName("Emmoria")
	, m_collection("files")
	, m_subcollection("")
	, mk_iconDir("image/logo/logo.png")
	, m_returnable()
	, m_textureContainer()
	, m_pEntityContainer(std::make_shared<EntityContainer>(m_textureContainer,
		sf::Vector2u(GameLoop::ms_screenReductionRatio, GameLoop::ms_screenReductionRatio),
		sf::VideoMode::getDesktopMode().width/GameLoop::ms_screenReductionRatio,
		sf::VideoMode::getDesktopMode().height/GameLoop::ms_screenReductionRatio))
	#ifdef DEBUG
		, m_debugMetricVisualizer()
	#endif
{
	GameLoop::ms_uScreenWidth = sf::VideoMode::getDesktopMode().width;
	GameLoop::ms_uScreenHeight = sf::VideoMode::getDesktopMode().height;
}

bool GameLoop::Start()
{
	s_pLogger->DebugLog(mk_type, "Gameloop started");
	auto pGameWindow = GetGameWindowPtr_();
	auto pDatabaseReader = GetDatabaseReaderPtr_();
	pDatabaseReader->LoadNewRegion(m_collection.c_str(), m_subcollection.c_str(), m_pEntityContainer);
	while (pGameWindow->isOpen()) { RunLoop_(pGameWindow, pDatabaseReader); }
	return true;
}

std::shared_ptr<sf::RenderWindow> GameLoop::GetGameWindowPtr_()
{
	auto pWindow(std::make_shared<sf::RenderWindow>
			(sf::VideoMode(GameLoop::ms_uScreenWidth, GameLoop::ms_uScreenHeight),
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
		switch (event.type)
		{
			case sf::Event::Closed: pGameWindow->close(); break;
			case sf::Event::GainedFocus: s_pLogger->DebugLog(mk_type, "Window Gained Focus"); break;
			case sf::Event::LostFocus: s_pLogger->DebugLog(mk_type, "Window Lost Focus"); break;
			default: break;
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
	if (m_returnable.updated)
	{
		UpdateMap_(pDatabaseReader);
	}
	#ifdef DEBUG
		m_debugMetricVisualizer.Update();
		pGameWindow->draw(m_debugMetricVisualizer);
	#endif
	pGameWindow->display();
	CheckForEvents_(pGameWindow);
}

void GameLoop::UpdateMap_(std::shared_ptr<DatabaseReader> pDatabaseReader)
{
	 	m_collection = m_returnable.collection;
		m_subcollection = m_returnable.subCollection;
		m_pEntityContainer = m_returnable.m_pNewStartingEntityContainer;
		s_pLogger->DebugLog(mk_type, (std::string("Loading new region ") + m_collection + std::string(".") + m_subcollection).c_str());
		pDatabaseReader->LoadNewRegion(m_collection.c_str(), m_subcollection.c_str(), m_pEntityContainer);
		m_pLocation->Reset();
		m_returnable = Returnable();
}

void GameLoop::UpdateAllEntities_()
{
	for (auto&& pEntity : m_pEntityContainer->GetUpdatableEntities())
	{
		auto returnable = pEntity->Update();
		if (returnable.m_pNewStartingEntityContainer)
		{
			s_pLogger->InfoLog(mk_type, "Loading new location");
			m_returnable.collection = returnable.collection;
			m_returnable.subCollection = returnable.subCollection;
			m_returnable.m_pNewStartingEntityContainer = returnable.m_pNewStartingEntityContainer;
			m_returnable.updated = true;
			break;
		}
	}
}

void GameLoop::DrawAllEntities_(
	std::shared_ptr<sf::RenderWindow> pGameWindow)
{
	//auto pair = m_pLocation->GetCurrentPosition();
	for (auto&& pEntity : m_pEntityContainer->GetDrawableTransformableEntities())
	{
		//pEntity->setPosition(sf::Vector2f(-pair.first, -pair.second));
		pGameWindow->draw(*pEntity);
	}
}