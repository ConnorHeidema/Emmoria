#ifndef FILE_BUTTON_HPP
#define FILE_BUTTON_HPP

#include "entity/EntityCombination.hpp"
#include "util/logger/Logger.hpp"

class FileButton
	: public DrawableTransformableIUpdatable
{
public:
	FileButton(
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
		, m_returnable()
	{
		m_font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-B.ttf");
		std::string fullyQualifiedCollection = GetStringValue_(element, "area");
		m_returnable.collection = fullyQualifiedCollection.substr(0, fullyQualifiedCollection.find('.'));
		m_returnable.subCollection = fullyQualifiedCollection.substr(fullyQualifiedCollection.find(".") + 1);
		//GetIntValue()
	}

	Returnable Update() override;
	bool ClickedInText_();
private:

	/**
	 * Gets a string from the supplied key in the db
	 * @param element The element itself
	 * @param key The key to search for
	 * @return The value of the key
	 */
	std::string GetStringValue_(bsoncxx::array::element element, std::string key);

	std::pair<int, int> GetPlayerPosition(bsoncxx::array::element element);

	LoggerType_t const mk_type;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	int m_characterSize;
	sf::Text m_text;
	std::string m_fileInfo;
	sf::Font m_font;
	int m_x;
	int m_y;
	mutable int m_height;
	mutable int m_width;
	Returnable m_returnable;
};

#endif
