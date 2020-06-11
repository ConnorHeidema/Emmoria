#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity/EntityCombination.hpp"
#include "entity/player/Player.hpp"

#include "entity/SharedParameters.hpp"

#include "util/logger/Logger.hpp"

class Player
	: public DrawableTransformableIInteractableIUpdatable
{

	static int const downFace;
	static int const rightFace;
	static int const upFace;
	static int const leftFace;

public:
	Player(
		std::shared_ptr<SharedParameters> pSharedParameters,
		std::shared_ptr<TileMap> pTileMap,
		bsoncxx::array::element element);

	virtual ~Player() {};

	Returnable Update() override;

	/**
	 * Utililsed to draw the player each frame
	 * @param target The target being drawn
	 * @param states The transformation done to the target
	 */
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:

	void CurrentPositionProcedure_();

	int GetCurrentFace_();
	void CurrentPhaseProcedure_();


	void PopulateQuad_(
		int const xTileIndex,
		int const yTileIndex);

	void DefineQuadCorners_(
		sf::Vertex* currentTile,
		int xTileIndex,
		int yTileIndex);

	void ApplyTexturesToCorners_(
		sf::Vertex* currentTile,
		int textureRow,
		int textureColumn);

	LoggerType_t const mk_type;

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;

	std::string const m_tilesetPath;
	sf::Vector2u const m_tileUnitSize;
	int m_x;
	int m_y;
	int m_currentPhase;
	int m_framesUntilAnimationChange;
	int m_currentFrame;
};


#endif
