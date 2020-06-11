#include "map/TileMap.hpp"
#include "util/logger/Logger.hpp"
#include "map/TextureContainer.hpp"

#include <string>

TileMap::TileMap(
		sf::Vector2u const tileUnitSize,
		unsigned int const tileWidth,
		unsigned int const tileHeight,
		TextureContainer& textureContainer)
			: DrawableTransformable(std::make_shared<SharedParameters>(0, 0, 0, 0), nullptr)
			, m_tileUnitSize(tileUnitSize)
			, m_tileWidth(tileWidth)
			, m_tileHeight(tileHeight)
			, m_quadVertices(4u)
			, mk_tileNotDefined(-1)
			, mk_type("TileMap")
			, m_textureContainer(textureContainer)
{
	m_screenArrayVect.assign(tileWidth * tileHeight, nullptr);
}

void TileMap::Load()
{
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(m_tileWidth * m_tileHeight * m_quadVertices);
	PopulateVertexArray_();
}

void TileMap::OnNotify(int x, int y)
{
	PopulateQuad_(x, y);
}

void TileMap::PrepareTile(int xIndex, int yIndex, std::shared_ptr<int> pSubTexture)
{
	m_screenArrayVect.at((yIndex * m_tileWidth) + xIndex) = pSubTexture;
}

bool TileMap::SetTextureFile(std::string const tilesetPath)
{
	m_tileset = *m_textureContainer.GetTexture(tilesetPath);
	return true;
}


void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = &m_tileset;
	target.draw(m_vertices, states);
}


void TileMap::PopulateVertexArray_()
{
	for (unsigned int xTileIndex = 0; xTileIndex < m_tileWidth; ++xTileIndex)
	{
		for (unsigned int yTileIndex = 0; yTileIndex < m_tileHeight; ++yTileIndex)
		{
			PopulateQuad_(xTileIndex, yTileIndex);
		}
	}
}

void TileMap::PopulateQuad_(
	int const xTileIndex,
	int const yTileIndex)
{
	int tileNumber = GetCurrentTileNumber_(xTileIndex, yTileIndex);
	if (tileNumber == mk_tileNotDefined)
	{
		return;
	}
	int textureColumn = tileNumber % (m_tileset.getSize().x / m_tileUnitSize.x);
	int textureRow = tileNumber / (m_tileset.getSize().x / m_tileUnitSize.x);

	sf::Vertex* currentTile = &m_vertices[(xTileIndex + yTileIndex * m_tileWidth) * 4];

	DefineQuadCorners_(currentTile, xTileIndex, yTileIndex);
	ApplyTexturesToCorners_(currentTile, textureColumn, textureRow);

}

int TileMap::GetCurrentTileNumber_(
	int xTileIndex,
	int yTileIndex)
{
	return (m_screenArrayVect[xTileIndex + yTileIndex * m_tileWidth] != nullptr ?
		*m_screenArrayVect[xTileIndex + yTileIndex * m_tileWidth] :
		mk_tileNotDefined);
}

void TileMap::DefineQuadCorners_(
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

void TileMap::ApplyTexturesToCorners_(
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
