#ifndef I_UPDATABLE_HPP
#define I_UPDATABLE_HPP

#include "entity/Entity.hpp"

#include "map/TileMap.hpp"
#include "entity/Returnable.hpp"

#include <bsoncxx/builder/stream/document.hpp>

#include <memory>

class IUpdatable
	: public Entity
{
public:
	IUpdatable(int x, int y, std::shared_ptr<TileMap> pTileMap /*tileMap*/) {}
	virtual Returnable Update() = 0;
	virtual ~IUpdatable() {};
};

#endif
