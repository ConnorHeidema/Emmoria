#ifndef I_INTERACTABLE_HPP
#define I_INTERACTABLE_HPP

#include "entity/SharedParameters.hpp"

#include "entity/Entity.hpp"

#include "map/TileMap.hpp"

#include "util/datastructure/QuadNode.hpp"

#include <bsoncxx/builder/stream/document.hpp>

#include <memory>

class IInteractable
	: public Entity
	, public QuadNode
{
public:
	IInteractable(
		std::shared_ptr<SharedParameters> pSharedParameters,
		std::shared_ptr<TileMap> /*tileMap*/)
		: QuadNode(pSharedParameters)
	{}

	virtual ~IInteractable() {};
};

#endif
