#include "entity/button/FileButton.hpp"

#include "util/DatabaseUtil.hpp"

#include <SFML/Graphics.hpp>

FileButton::FileButton(
		int x,
		int y,
		std::shared_ptr<TileMap> pTileMap,
		bsoncxx::array::element element)
		: DrawableTransformableIUpdatable(x, y, pTileMap)
		, mk_type("FileButton")
		, m_characterSize(20)
		, m_text()
		, m_fileInfo("No info found")
		, m_x(x)
		, m_y(y)
		, m_height(0)
		, m_width(0)
		, m_padding(10)
		, m_returnable()
{
	std::string fullyQualifiedCollection = DatabaseUtil::GetStringValueFromKeyDb(element, "area");
	m_returnable.collection = fullyQualifiedCollection.substr(0, fullyQualifiedCollection.find('.'));
	m_returnable.subCollection = fullyQualifiedCollection.substr(fullyQualifiedCollection.find(".") + 1);
	//GetIntValue()

	SetText_();
	SetRect_();
}

void FileButton::SetText_()
{
	m_font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-B.ttf");
	m_thisText.setFont(m_font);
	m_thisText.setCharacterSize(m_characterSize);
	m_thisText.setString(m_returnable.collection + ":" + m_returnable.subCollection);

	m_height = int(m_thisText.getGlobalBounds().height);
	m_width = int(m_thisText.getGlobalBounds().width);

	m_thisText.setPosition(sf::Vector2f(m_x - m_width/2, m_y - m_height/2));
	m_thisText.setFillColor(sf::Color::White);
}


void FileButton::SetRect_()
{
	m_thisRect.setPosition(sf::Vector2f(m_x - m_width/2 - m_padding, m_y- m_height/2 - m_padding));
	m_thisRect.setSize(sf::Vector2f(m_width + 2 * m_padding, m_height + 2 * m_padding));
	m_thisRect.setOutlineColor(sf::Color::Black);
	m_thisRect.setFillColor(sf::Color::Blue);
}

void FileButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_thisRect, states);
	target.draw(m_thisText, states);
}

Returnable FileButton::Update()
{
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) || !ClickedInText_())
	{
		return Returnable();
	}
	// Processing
	m_returnable.updated = true;
	return m_returnable;
}

bool FileButton::ClickedInText_()
{
	return
		(int(sf::Mouse::getPosition().x) > m_x &&
		int(sf::Mouse::getPosition().x) < m_x + m_width &&
		int(sf::Mouse::getPosition().y) > m_y &&
		int(sf::Mouse::getPosition().y) < m_y + m_height);
}
