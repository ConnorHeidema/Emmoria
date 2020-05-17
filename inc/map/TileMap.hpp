#ifndef TILE_MAP_HPP
#define TILE_MAP_HPP

#include "../../inc/util/logger/ILogger.hpp"

#include <SFML/Graphics.hpp>

using TileMapSubTextureArray = int;

/**
 * The TileMap aggregates objects that may be drawn on a grid into a single drawable object.
 * This is convenient to reduce the number of openGL draw calls significantly
 */
class TileMap
	: public sf::Drawable
	, public sf::Transformable
{
public:
	/**
	 * The constructor, sets the initial state of the tilemap along with the tileset that will be used
	 * @param tileUnitSize the size of each unit within the texture file
	 * @param tileWidth The width of a unit on the screen
	 * @param tileHeight The height of a unit on the screen
	 */
	TileMap(
		sf::Vector2u const tileUnitSize,
		unsigned int const tileWidth,
		unsigned int const tileHeight);

	/**
	 * Prepares a single tile to be drawn
	 * @param xIndex The horizontal location to put the subtexture
	 * @param yIndex The vertical location to put the subtexture
	 * @param subTexture The index of the subtexture to use in the texture file
	 */
	void PrepareTile(int xIndex, int yIndex, int subTexture);

	/**
	 * Sets and loads a texture file for the tileset to use
	 * @param tilesetPath where the texture file is
	 * @return whether the load was successful or not for the file
	 */
	bool SetTextureFile(std::string const tilesetPath);

	/**
	 * Gets the drawable in a state that is ready to get drawn.
	 * This should be called after PrepareTile has been called
	 * on each tile that should be drawn on the screen.
	 */
	void Load();
private:
	/**
	 * Labels the index of the quad points to more easily
	 * understand which point matches to which corner.
	 */
	enum QuadPosition
	{
		TOP_LEFT = 0,
		TOP_RIGHT = 1,
		BOTTOM_RIGHT = 2,
		BOTTOM_LEFT = 3
	};

	/**
	 * utililsed to draw the array to the window.
	 * @param target The target being drawn
	 * @param states The transformation done to the target
	 */
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	/**
	 * Populates the entire array of vertexes to be drawn
	 */
	void PopulateVertexArray_();

	/**
	 * Populates a single tile at the index x and y
	 * This actually creates the vertexes while
	 * PrepareTile does the linking of the texture initially
	 * @param xTileIndex the x position to draw
	 * @param yTileIndex the y position to draw
	 */
	void PopulateQuad_(int const xTileIndex, int const yTileIndex);

	/**
	 * Gets the current tile that PopulateVertexArray_ is working on
	 * @param xTileIndex The index of the x tile
	 * @param yTileIndex The index of the y tile
	 * @return the tile number
	 */
	int GetCurrentTileNumber_(int xTileIndex, int yTileIndex);

	/**
	 * Defines the positions of the vertexes for an individual quad
	 * @param currentTile the current tile
	 * @param xTileIndex the x indexed position
	 * @param yTileIndex the y indexed position
	 */
	void DefineQuadCorners_(sf::Vertex* currentTile, int xTileIndex, int yTileIndex);

	/**
	 * Applies the subtexture to a quad
	 * @param currentTile the current tile
	 * @param textureRow the x indexed position of the subtexture
	 * @param textureColumn the y indexed position of the subtexture
	 */
	void ApplyTexturesToCorners_(sf::Vertex* currentTile, int textureRow, int textureColumn);

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;

	std::string const m_tilesetPath;
	sf::Vector2u const m_tileUnitSize;
	unsigned int const m_tileWidth;
	unsigned int const m_tileHeight;

	unsigned int const m_quadVertices;

	std::vector<int> m_screenArrayVect;

	LoggerType_t const mk_type;
};
#endif
