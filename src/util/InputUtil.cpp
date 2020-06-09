#include "util/InputUtil.hpp"

#include <SFML/Graphics.hpp>

bool InputUtil::WasdPressed()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::D);
}