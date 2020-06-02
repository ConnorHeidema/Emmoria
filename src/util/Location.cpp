#include "util/Location.hpp"

#include <SFML/Graphics.hpp>

Location::Location(std::pair<int, int> location)
	: m_currentPosition(location)
	, m_positionDelta(1)
{
}

std::pair<int,int> Location::GetCurrentPosition()
{
	return m_currentPosition;
}

void Location::UpdateCurrentPosition()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_currentPosition.second -= m_positionDelta;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_currentPosition.first -= m_positionDelta;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_currentPosition.second += m_positionDelta;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_currentPosition.first += m_positionDelta;
	}
}

void Location::Reset()
{
	m_currentPosition.first = 0;
	m_currentPosition.second = 0;
}
