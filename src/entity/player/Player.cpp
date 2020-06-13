#include "entity/player/Player.hpp"

#include "util/enum/QuadPosition.hpp"

#include "util/InputUtil.hpp"

#include <cstdlib>

int const Player::downFace = 0;
int const Player::rightFace = 1;
int const Player::upFace = 2;
int const Player::leftFace = 3;

Player::Player(
	std::shared_ptr<SharedParameters> pSharedParameters,
	std::shared_ptr<TileMap> pTileMap,
	bsoncxx::array::element element)
		: DrawableTransformableIInteractableIUpdatable(pSharedParameters, pTileMap)
		, mk_type("Player")
		, m_tileset()
		, m_tilesetPath("image/player/player.png")
		, m_tileUnitSize(sf::Vector2i(120, 120))
		, m_x(pSharedParameters->m_left)
		, m_y(pSharedParameters->m_top)
		, m_currentPhase(0)
		, m_framesUntilAnimationChange(15)
		, m_currentFrame(0)
{
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(4);
	m_tileset.loadFromFile(m_tilesetPath);
	m_tileset = *pTileMap->m_textureContainer.GetTexture(m_tilesetPath);
	PopulateQuad_(pSharedParameters->m_left, pSharedParameters->m_top);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = &m_tileset;
	target.draw(m_vertices, states);
}

int Player::GetCurrentFace_()
{
	int xDelta = sf::Mouse::getPosition().x - (m_x + m_tileUnitSize.x/2);
	int yDelta = sf::Mouse::getPosition().y - (m_y + m_tileUnitSize.y/2);
	int wideScreenFactor = 2;
	return (std::abs(xDelta/wideScreenFactor) > std::abs(yDelta) ?
				(xDelta > 0 ? rightFace : leftFace) :
				(yDelta > 0 ? downFace : upFace));
}

void Player::CurrentPhaseProcedure_()
{
	if (m_currentFrame % m_framesUntilAnimationChange == 0)
	{
		m_currentPhase = (InputUtil::WasdPressed() ? (m_currentPhase + 1) % 4 : 0);
	}
}

void Player::CurrentPositionProcedure_()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_y -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_x -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_y += 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_x += 1;
	}
}

Returnable Player::Update()
{
	m_currentFrame++;
	int currentFace = GetCurrentFace_();
	CurrentPhaseProcedure_();
	CurrentPositionProcedure_();

	sf::Vertex* currentTile = &m_vertices[0];
	ApplyTexturesToCorners_(currentTile, currentFace + (4 * m_currentPhase), 0);
	DefineQuadCorners_(currentTile, m_x, m_y);
	return Returnable();
}

void Player::PopulateQuad_(
	int const xTileIndex,
	int const yTileIndex)
{
	int textureColumn = 0;
	int textureRow = 0;

	sf::Vertex* currentTile = &m_vertices[0];

	DefineQuadCorners_(currentTile, xTileIndex, yTileIndex);
	ApplyTexturesToCorners_(currentTile, textureColumn, textureRow);
}

void Player::DefineQuadCorners_(
	sf::Vertex* currentTile,
	int xTileIndex,
	int yTileIndex)
{
	currentTile[TOP_LEFT].position = sf::Vector2f(
		xTileIndex,
		yTileIndex);

	currentTile[TOP_RIGHT].position = sf::Vector2f(
		xTileIndex + m_tileUnitSize.x,
		yTileIndex);

	currentTile[BOTTOM_RIGHT].position = sf::Vector2f(
		xTileIndex + m_tileUnitSize.x,
		yTileIndex + m_tileUnitSize.y);

	currentTile[BOTTOM_LEFT].position = sf::Vector2f(
		xTileIndex,
		yTileIndex + m_tileUnitSize.y);
}

void Player::ApplyTexturesToCorners_(
	sf::Vertex* currentTile,
	int textureRow,
	int textureColumn)
{
	currentTile[TOP_LEFT].texCoords = sf::Vector2f
		(textureRow * m_tileUnitSize.x,
		textureColumn * m_tileUnitSize.y);

	currentTile[TOP_RIGHT].texCoords = sf::Vector2f(
		(textureRow + 1) * m_tileUnitSize.x,
		textureColumn * m_tileUnitSize.y);

	currentTile[BOTTOM_RIGHT].texCoords = sf::Vector2f(
		(textureRow + 1) * m_tileUnitSize.x,
		(textureColumn + 1) * m_tileUnitSize.y);

	currentTile[BOTTOM_LEFT].texCoords = sf::Vector2f(
		textureRow * m_tileUnitSize.x,
		(textureColumn + 1) * m_tileUnitSize.y);
}
