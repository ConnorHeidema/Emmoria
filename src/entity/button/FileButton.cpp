#include "entity/button/FileButton.hpp"

void FileButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	// states.texture = &m_tileset;
	// target.draw(m_vertices, states);
}
