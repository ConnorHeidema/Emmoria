#ifndef I_UPDATABLE_HPP
#define I_UPDATABLE_HPP

#include "map/TileMap.hpp"
#include <memory>

class IUpdatable
{
public:
	IUpdatable(int x, int y, std::shared_ptr<TileMap> pTileMap /*tileMap*/) {}
	virtual void Update() = 0;
	virtual ~IUpdatable() {};
};

#endif
