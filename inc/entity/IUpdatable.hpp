#ifndef I_UPDATABLE_HPP
#define I_UPDATABLE_HPP

#include "entity/SharedParameters.hpp"

#include "entity/Entity.hpp"

#include "map/TileMap.hpp"
#include "entity/Returnable.hpp"

#include <bsoncxx/builder/stream/document.hpp>

#include <memory>

class IUpdatable
	: public Entity
{
public:
	IUpdatable(std::shared_ptr<SharedParameters> /*pSharedParameters*/, std::shared_ptr<TileMap> /*pTileMap*/) {}
	virtual Returnable Update() = 0;
	virtual ~IUpdatable() {};
};

#endif
