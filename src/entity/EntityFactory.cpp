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

void EntityFactory::LoadEntityOntoContainer(
	bsoncxx::array::element element,
	EntityContainer& entityContainer)
{
	int x = -1;
	int y = -1;
	bsoncxx::document::element indexObject{element["index"]};
	auto stringName = GetStringName_(element);
	if (indexObject.length() != 0)
	{
		Coordinate coordinate = GetCoordinate_(element);
		x = coordinate.first;
		y = coordinate.second;
	}
	#define LOAD_ENTITY(entity, interface1) \
		else if (stringName == #entity) \
		{ \
			entityContainer.Insert##interface1##Entity(std::make_shared<entity>(x, y)); \
		}
	#define LOAD_ENTITY2(entity, interface1, interface2) \
		else if (stringName == #entity) \
		{ \
			entityContainer.Insert##interface1##interface2##Entity(std::make_shared<entity>(x, y)); \
			return; \
		}
	#define LOAD_ENTITY3(entity, interface1, interface2, interface3) \
		else if (stringName == #entity) \
		{ \
			entityContainer.Insert##interface1##interface2##interface3##Entity(std::make_shared<entity>(x, y)); \
			return; \
		}

		if (false) {}
		LOAD_ENTITY2(Grass, IGridded, IUpdatable)
		LOAD_ENTITY(RoyalMat, IGridded)
		LOAD_ENTITY(BottomWall, IGridded)
		LOAD_ENTITY(UpperWall, IGridded)
		LOAD_ENTITY(RockGround, IGridded)
		LOAD_ENTITY(LeftWall, IGridded)
		LOAD_ENTITY(RightWall, IGridded)
		LOAD_ENTITY(Corner, IGridded)

	#undef LOAD_ENTITY3
	#undef LOAD_ENTITY2
	#undef LOAD_ENTITY
}

void EntityFactory::MapGriddablesToTilemap(
	EntityContainer& entityContainer,
	std::string tilemapName)
{
	entityContainer.m_pTileMap->SetTextureFile(tilemapName);
	for (auto&& gridded : entityContainer.GetGriddedEntities())
	{
		entityContainer.m_pTileMap->PrepareTile(gridded->m_xIndex, gridded->m_yIndex, gridded->GetSubTextureIndexPtr());
	}
}

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
	int x;
	int y;
	#define CREATE_ENTITY(entity) \
		else if (stringName == #entity) \
		{ \
			return std::make_shared<entity>(x, y); \
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
	return std::make_shared<Grass>(-1, -1);
}
