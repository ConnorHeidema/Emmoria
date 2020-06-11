#include "entity/button/FileButton.hpp"
#include "entity/player/Player.hpp"

#include "util/DatabaseUtil.hpp"

#include "entity/EntityFactory.hpp"

#include "entity/SharedParameters.hpp"

#include "loop/GameLoop.hpp"

#include <SFML/Graphics.hpp>

unsigned int FileButton::ms_instanceCount = 0;

FileButton::FileButton(
		std::shared_ptr<SharedParameters> pSharedParameters,
		std::shared_ptr<TileMap> pTileMap,
		bsoncxx::array::element element)
		: DrawableTransformableIUpdatable(pSharedParameters, pTileMap)
		, mk_type("FileButton")
		, m_characterSize(20)
		, m_text()
		, m_fileInfo("No info found")
		, m_x(pSharedParameters->m_left)
		, m_y(pSharedParameters->m_top)
		, m_height(0)
		, m_width(0)
		, m_padding(10)
		, m_playerX(0)
		, m_playerY(0)
		, mk_defaultColor(sf::Color::Blue)
		, mk_MouseOverColor(sf::Color::Green)
		, m_returnable()
		, m_pTileMap(pTileMap)
		, m_element(element) // m_element cannot be used outside of the constructor currently because the document it
							 // looks at loses scope
{
	std::string fullyQualifiedCollection = DatabaseUtil::GetStringValueFromKeyDb(element, "area");
	m_returnable.collection = fullyQualifiedCollection.substr(0, fullyQualifiedCollection.find('.'));
	m_returnable.subCollection = fullyQualifiedCollection.substr(fullyQualifiedCollection.find(".") + 1);

	auto playerCoordinates = DatabaseUtil::GetPositionValueFromKeyDb_(element, "player");
	m_playerX = playerCoordinates.first;
	m_playerY = playerCoordinates.second;
	SetText_();
	SetRect_();
	ms_instanceCount++;
}

FileButton::~FileButton()
{
	ms_instanceCount--;
}

void FileButton::SetText_()
{
	m_font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-B.ttf");
	m_thisText.setFont(m_font);
	m_thisText.setCharacterSize(m_characterSize);
	m_thisText.setString(m_returnable.collection + ":" + m_returnable.subCollection);

	m_height = int(m_thisText.getGlobalBounds().height);
	m_width = int(m_thisText.getGlobalBounds().width);

	m_y += ms_instanceCount * m_height * 3;

	m_thisText.setPosition(sf::Vector2f(m_x - m_width/2, m_y - m_height/2));
	m_thisText.setFillColor(sf::Color::White);
}


void FileButton::SetRect_()
{
	m_thisRect.setPosition(sf::Vector2f(m_x - m_width/2 - m_padding, m_y- m_height/2 - m_padding));
	m_thisRect.setSize(sf::Vector2f(m_width + 2 * m_padding, m_height + 2 * m_padding));
	m_thisRect.setOutlineColor(sf::Color::Black);
	m_thisRect.setFillColor(mk_defaultColor);

	m_height = int(m_thisRect.getGlobalBounds().height);
	m_width = int(m_thisRect.getGlobalBounds().width);
}

void FileButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_thisRect, states);
	target.draw(m_thisText, states);
}

Returnable FileButton::Update()
{
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) || !MouseInRectangle_())
	{
		m_thisRect.setFillColor(MouseInRectangle_() ? mk_MouseOverColor : mk_defaultColor);
		return Returnable();
	}
	s_pLogger->DebugLog(mk_type, "Updating filebutton");
	m_returnable.m_pNewStartingEntityContainer = std::make_shared<EntityContainer>(
		m_pTileMap->m_textureContainer,
		sf::Vector2u(GameLoop::ms_screenReductionRatio, GameLoop::ms_screenReductionRatio),
		GameLoop::ms_uScreenWidth/GameLoop::ms_screenReductionRatio,
		GameLoop::ms_uScreenHeight/GameLoop::ms_screenReductionRatio);

	s_pLogger->DebugLog(mk_type, "after making entitycontainer");
	int x = m_playerX;
	int y = m_playerY;
	std::shared_ptr<SharedParameters> pSharedParameters = std::make_shared<SharedParameters>();
	pSharedParameters->m_left = x;
	pSharedParameters->m_top = y;
	pSharedParameters->m_right = x + 120;
	pSharedParameters->m_bottom = y + 120;
	s_pLogger->DebugLog(mk_type, "Before loading player");
	m_returnable.
		m_pNewStartingEntityContainer->
			InsertDrawableTransformableIInteractableIUpdatableEntity(
				std::make_shared<Player>(pSharedParameters, m_pTileMap, m_element));
	s_pLogger->DebugLog(mk_type, "After loading player");
	m_returnable.updated = true;
	return m_returnable;
}

bool FileButton::MouseInRectangle_() const
{
	return
		(int(sf::Mouse::getPosition().x) > m_x - m_width/2 &&
		 int(sf::Mouse::getPosition().x) < m_x + m_width/2 &&
		 int(sf::Mouse::getPosition().y) > m_y - m_height/2 &&
		 int(sf::Mouse::getPosition().y) < m_y + m_height/2);
}
