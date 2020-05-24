#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <tuple>

/**
 * This class responds to user button presses in order to update the screen being displayed
 * It holds the total delta in position so that the screen can show properly where things
 * are
 */
class Location
{
public:
	/**
	 * Constructor for location
	 * @param location the beginning location within the region
	 */
	Location(std::pair<int, int> location);

	/**
	 * Gets the current position
	 * @return the current position
	 */
	std::pair<int,int> GetCurrentPosition();

	/**
	 * Updates the current position if certain keys are pressed
	 */
	void UpdateCurrentPosition();
private:
	std::pair<int, int> m_currentPosition;
	int const m_positionDelta;
};

#endif
