#ifndef I_INTERACTABLE_HPP
#define I_INTERACTABLE_HPP

#include "entity/Entity.hpp"

#include "map/TileMap.hpp"

#include <bsoncxx/builder/stream/document.hpp>

#include <memory>

class IInteractable
	: public Entity
{
public:
	IInteractable(int x, int y, std::shared_ptr<TileMap> pTileMap /*tileMap*/) {}
	virtual ~IInteractable() {};
};

#endif
