#ifndef INTERACTABLE_ENTITY_FACTORY_HPP
#define INTERACTABLE_ENTITY_FACTORY_HPP

#include "../../../inc/map/TileMap.hpp"
#include "../../../inc/entity/interactable/IInteractableEntity.hpp"

#include <bsoncxx/builder/stream/document.hpp>

#include <memory>
#include <string>

using Coordinate = std::pair<int, int>;

class InteractableEntityFactory
{
public:
	static std::shared_ptr<IInteractableEntity> CreateInteractableEntity(bsoncxx::array::element element, std::shared_ptr<TileMap> m_pBottomLayerTileMap);
private:
	static Coordinate GetCoordinate_(bsoncxx::array::element element);
	static std::string GetStringName_(bsoncxx::array::element element);
};

#endif
