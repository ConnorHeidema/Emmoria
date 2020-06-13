#ifndef GAME_LOOP_HPP
#define GAME_LOOP_HPP

#include "database/DatabaseReader.hpp"

#include "util/Location.hpp"

#include "map/TextureContainer.hpp"

#ifdef DEBUG
	#include "debug/DebugMetricVisualizer.hpp"
#endif

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

	static unsigned int ms_uScreenWidth;
	static unsigned int ms_uScreenHeight;

	static unsigned int ms_screenReductionRatio;

private:

	/**
	 * Gets a shared pointer to the gameWindow
	 * @return the window
	 */
	std::shared_ptr<sf::RenderWindow> GetGameWindowPtr_();

	/**
	 * Sets the icon for the application window
	 * @param pGameWindow The constructed window
	 */
	void SetIcon_(std::shared_ptr<sf::Window> pGameWindow);

	/**
	 * Gets a shared pointer to the database reader.
	 * @return the databaseReader
	 */
	std::shared_ptr<DatabaseReader> GetDatabaseReaderPtr_();

	void CheckForEvents_(std::shared_ptr<sf::Window> pGameWindow);

	/**
	 * Runs everything that needs to be run within the game loop
	 * @param pGameWindow the window that is being written to
	 * @param pDatabaseReader the databaseReader
	 */
	void RunLoop_(
		std::shared_ptr<sf::RenderWindow> pGameWindow,
		std::shared_ptr<DatabaseReader> pDatabaseReader);

	/**
	 * Updates all the updatable entities in the current containers updatable entities
	 */
	void UpdateAllEntities_();

	void InteractAllEntities_();

	/**
	 * Writes all the entitiess to the screen
	 * @param pDatabaseReader the database reader which provides the entities
	 */
	void DrawAllEntities_(
		std::shared_ptr<sf::RenderWindow> pGameWindow);

	/**
	 * Updates the location that is loaded once a new returnable has been made
	 * @param pDatabaseReader a pointer to the database reader
	 */
	void UpdateMap_(std::shared_ptr<DatabaseReader> pDatabaseReader);

	LoggerType_t const mk_type;

	std::shared_ptr<Location> m_pLocation;

	unsigned int const mk_uFrameRate;
	char const * const mk_windowName;
	std::string m_collection;
	std::string m_subcollection;
	char const * const mk_iconDir;
	Returnable m_returnable;
	TextureContainer m_textureContainer;

	std::shared_ptr<EntityContainer> m_pEntityContainer;

	#ifdef DEBUG
		DebugMetricVisualizer m_debugMetricVisualizer;
	#endif
};

#endif
