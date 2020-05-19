#include "../../inc/entity/EntityFactory.hpp"
#include "../../inc/entity/simple/Grass.hpp"
#include "../../inc/entity/simple/BottomWall.hpp"
#include "../../inc/entity/simple/Corner.hpp"
#include "../../inc/entity/simple/LeftWall.hpp"
#include "../../inc/entity/simple/RightWall.hpp"
#include "../../inc/entity/simple/RockGround.hpp"
#include "../../inc/entity/simple/RoyalMat.hpp"
#include "../../inc/entity/simple/UpperWall.hpp"

#include "../../inc/util/logger/Logger.hpp"

std::shared_ptr<IGridded> EntityFactory::CreateInteractableEntity(
	bsoncxx::array::element element,
	std::shared_ptr<TileMap> pBottomLayerTileMap)
{
	auto stringName = GetStringName_(element);

	std::shared_ptr<IGridded> createdEntity =
		GetInteractableEntity_(stringName);

	auto coordinate = GetCoordinate_(element);
	pBottomLayerTileMap->PrepareTile(
		coordinate.first,
		coordinate.second,
		createdEntity->GetSubTextureIndexPtr());
	return createdEntity;
}

Coordinate EntityFactory::GetCoordinate_(bsoncxx::array::element element)
{
	bsoncxx::document::element position{element["index"]};
	bsoncxx::document::element xPositionElement{position["x"]};
	int xIndex = xPositionElement.get_int32();
	bsoncxx::document::element yPositionElement{position["y"]};
	int yIndex = yPositionElement.get_int32();
	return Coordinate(xIndex, yIndex);
}

std::string EntityFactory::GetStringName_(bsoncxx::array::element element)
{
	bsoncxx::document::element entityName{element["name"]};
	auto entityNameValue = entityName.get_utf8().value;
	return entityNameValue.to_string();
}

std::shared_ptr<IGridded> EntityFactory::GetInteractableEntity_(std::string const& stringName)
{

	#define CREATE_ENTITY(x) \
		else if (stringName == #x) \
		{ \
			return std::make_shared<x>(); \
		}

		if (false){}
		CREATE_ENTITY(Grass) CREATE_ENTITY(RoyalMat) CREATE_ENTITY(BottomWall)
		CREATE_ENTITY(UpperWall) CREATE_ENTITY(RockGround) CREATE_ENTITY(LeftWall)
		CREATE_ENTITY(RightWall) CREATE_ENTITY(Corner)
		else { return GetDefaultInteractableEntity_(); }

	#undef CREATE_ENTITY
}

std::shared_ptr<IGridded> EntityFactory::GetDefaultInteractableEntity_()
{
	return std::make_shared<Grass>();
}
