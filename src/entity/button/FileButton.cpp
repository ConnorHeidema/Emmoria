#include "entity/button/FileButton.hpp"

#include <SFML/Graphics.hpp>

void FileButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Text thisText;
	thisText.setFont(m_font);
	thisText.setPosition(sf::Vector2f(m_x, m_y));
	thisText.setCharacterSize(m_characterSize);
	thisText.setFillColor(sf::Color::White);
	thisText.setString(m_fileInfo);
	target.draw(thisText, states);
	m_height = int(thisText.getGlobalBounds().height);
	m_width = int(thisText.getGlobalBounds().width);
}

Returnable FileButton::Update()
{

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && ClickedInText_())
	{
		m_returnable.updated = true;
		m_fileInfo = "Left was clicked in text";
		return m_returnable;
	}
	else
	{
		m_fileInfo = "Left not clicked in text";
	}
	return Returnable();
}

bool FileButton::ClickedInText_()
{
	if (int(sf::Mouse::getPosition().x) > m_x && int(sf::Mouse::getPosition().x) < m_x + m_width &&
		int(sf::Mouse::getPosition().y) > m_y && int(sf::Mouse::getPosition().y) < m_y + m_height)
	{
		return true;
	}
	return false;
}

std::pair<int, int> FileButton::GetPlayerPosition(bsoncxx::array::element element)
{
	bsoncxx::document::element position{element["position"]};
	bsoncxx::document::element xPositionElement{position["x"]};
	int xIndex = xPositionElement.get_int32();
	bsoncxx::document::element yPositionElement{position["y"]};
	int yIndex = yPositionElement.get_int32();
	return std::pair<int, int>(xIndex, yIndex);
}


std::string FileButton::GetStringValue_(bsoncxx::array::element element, std::string key)
{
	bsoncxx::document::element entityName{element["area"]};
	auto entityNameValue = entityName.get_utf8().value;
	return entityNameValue.to_string();
}
