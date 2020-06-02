#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity/EntityCombination.hpp"
#include "entity/player/Player.hpp"

class Player
	: public DrawableTransformableIInteractableIUpdatable
{
public:
	Player(int x, int y, std::shared_ptr<TileMap> pTileMap,
		bsoncxx::array::element element) :
		DrawableTransformableIInteractableIUpdatable(x, y, pTileMap),
		m_ptmp(std::make_shared<int>(0)) // Player looks like a hole for now
	{}

	virtual ~Player() {};

	Returnable Update() override;

private:
	std::shared_ptr<int> m_ptmp;
};

#endif
