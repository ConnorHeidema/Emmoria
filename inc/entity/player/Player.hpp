#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity/EntityCombination.hpp"

class Player
	: public DrawableTransformableIInteractableIUpdatable
{
public:
	Player(int x, int y, std::shared_ptr<TileMap> pTileMap) :
		DrawableTransformableIInteractableIUpdatable(x, y, pTileMap),
		m_ptmp(std::make_shared<int>(11)) // Player looks like a hole for now
	{}

	virtual ~Player() {};

	void Update() override;

private:
	std::shared_ptr<int> m_ptmp;
};

#endif
