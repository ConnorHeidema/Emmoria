#ifndef I_INTERACTABLE_HPP
#define I_INTERACTABLE_HPP

#include "map/TileMap.hpp"
#include <memory>

class IInteractable
{
public:
	IInteractable(int x, int y, std::shared_ptr<TileMap> pTileMap /*tileMap*/) {}
	virtual ~IInteractable() {};
};

#endif
