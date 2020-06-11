#ifndef I_INTERACTABLE_HPP
#define I_INTERACTABLE_HPP

#include "entity/SharedParameters.hpp"

#include "entity/Entity.hpp"

#include "map/TileMap.hpp"

#include <bsoncxx/builder/stream/document.hpp>

#include <memory>

class IInteractable
	: public Entity
{
public:
	IInteractable(
		std::shared_ptr<SharedParameters> pSharedParameters,
		std::shared_ptr<TileMap> /*tileMap*/)
	{}

	virtual ~IInteractable() {};
};

#endif
