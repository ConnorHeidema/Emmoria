#ifndef DEBUG_METRIC_VISUALIZER_HPP
#define DEBUG_METRIC_VISUALIZER_HPP

#include "../../inc/util/logger/Logger.hpp"

#include <SFML/Graphics.hpp>

#include <memory>
#include <string>

/**
 * The debug metric visualizer is meant to help developers
 * to know background things going on in the program
 * To use it, draw it like any other drawable in the game loop
 */
class DebugMetricVisualizer
	: public sf::Drawable
{
public:
	/**
	 * Empty initializes a lot of variables that will track how
	 * the game is performing
	 */
	DebugMetricVisualizer();

	/**
	 * Each frame should update the metrics received
	 */
	void Update();

private:
	/**
	 * Draws the info gathered from the update
	 * @param target The target that will be drawn with
	 * @param states The renderstate the we want the target to be in
	 * 				 any transform may be applied leveraging this parameter
	 */
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	/**
	 * Gets the relevant string for the time elapsed.
	 * @return The string to print
	 */
	std::string GetTimeString_();

	/**
	 * Checks the keys that have been pressed on an update.
	 */
	void CheckKeys_();

	/**
	 * Checks if the left or right mouse button have been clicked
	 */
	void CheckMouse_();

	/**
	 * Gets the final string that should be printed to the screen
	 * @return The total debug string to return
	 */
	std::string GetDebugString_() const;

	LoggerType_t m_type;

	int m_characterSize;

	sf::Font m_font;

	std::string m_lastCharactersPressed;

	std::string m_leftMousePositionPressed;
	std::string m_RightMousePositionPressed;

	std::string m_timeRun;
	int m_minutesElapsed;
	int m_secondsElapsed;

	sf::Clock m_clock;

	int m_framesInSecond;
	int m_lastSeconds;
	std::string m_frameCountString;
};

#endif
