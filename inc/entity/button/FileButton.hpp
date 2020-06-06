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
		bsoncxx::array::element element);

	Returnable Update() override;

	bool MouseInRectangle_();

	~FileButton();

private:

	static unsigned int ms_instanceCount;

	/**
	 * Sets the text upon initialization of the file data
	 */
	void SetText_();

	/**
	 * Sets the bounding rectangle for the text that will be seen
	 */
	void SetRect_();

	sf::Text m_thisText;
	sf::RectangleShape m_thisRect;

	LoggerType_t const mk_type;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	int m_characterSize;
	sf::Text m_text;
	std::string m_fileInfo;
	sf::Font m_font;
	int m_x;
	int m_y;
	int m_height;
	int m_width;
	int m_padding;

	sf::Color const mk_defaultColor;
	sf::Color const mk_MouseOverColor;

	Returnable m_returnable;
	bsoncxx::array::element m_element;
};

#endif
