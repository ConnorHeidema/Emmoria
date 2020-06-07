#include "entity/player/Player.hpp"

#include "util/enum/QuadPosition.hpp"

#include <cstdlib>

int const Player::downFace = 0;
int const Player::rightFace = 1;
int const Player::upFace = 2;
int const Player::leftFace = 3;

Player::Player(int x, int y, std::shared_ptr<TileMap> pTileMap,
	bsoncxx::array::element element) :
		DrawableTransformableIInteractableIUpdatable(x, y, pTileMap),
		m_tileset(),
		m_tilesetPath("image/player/player.png"),
		m_tileUnitSize(sf::Vector2i(120, 120)),
		m_x(x),
		m_y(y),
		m_currentDirection(0),
		mk_type("Player")
{
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(4);
	m_tileset.loadFromFile(m_tilesetPath);
	m_tileset = *pTileMap->m_textureContainer.GetTexture(m_tilesetPath);
	PopulateQuad_(x, y);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = &m_tileset;
	target.draw(m_vertices, states);
}


Returnable Player::Update()
{
	int xDelta = sf::Mouse::getPosition().x - (m_x + m_tileUnitSize.x/2);
	int yDelta = sf::Mouse::getPosition().y - (m_y + m_tileUnitSize.y/2);
	int wideScreenFactor = 2;
	if (std::abs(xDelta/wideScreenFactor) > std::abs(yDelta))
	{
		m_currentDirection = (xDelta > 0 ? rightFace : leftFace);
	}
	else
	{
		m_currentDirection = (yDelta > 0 ? downFace : upFace);
	}
	sf::Vertex* currentTile = &m_vertices[0];
	ApplyTexturesToCorners_(currentTile, m_currentDirection, 0);
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
