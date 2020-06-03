#include "entity/player/Player.hpp"

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = &m_tileset;
	target.draw(m_vertices, states);
}


Returnable Player::Update()
{
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
		xTileIndex * m_tileUnitSize.x,
		yTileIndex * m_tileUnitSize.y);

	currentTile[TOP_RIGHT].position = sf::Vector2f(
		(xTileIndex + 1) * m_tileUnitSize.x,
		yTileIndex * m_tileUnitSize.y);

	currentTile[BOTTOM_RIGHT].position = sf::Vector2f(
		(xTileIndex + 1) * m_tileUnitSize.x,
		(yTileIndex + 1) * m_tileUnitSize.y);

	currentTile[BOTTOM_LEFT].position = sf::Vector2f(
		xTileIndex * m_tileUnitSize.x,
		(yTileIndex + 1) * m_tileUnitSize.y);
}

void Player::ApplyTexturesToCorners_(
	sf::Vertex* currentTile,
	int textureRow,
	int textureColumn)
{
		s_pLogger->WarningLog(mk_type, "HERE4");
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
