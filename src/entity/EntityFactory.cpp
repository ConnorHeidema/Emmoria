#include "entity/EntityFactory.hpp"
#include "entity/simple/Grass.hpp"
#include "entity/simple/BottomWall.hpp"
#include "entity/simple/Corner.hpp"
#include "entity/simple/LeftWall.hpp"
#include "entity/simple/RightWall.hpp"
#include "entity/simple/RockGround.hpp"
#include "entity/simple/RoyalMat.hpp"
#include "entity/simple/UpperWall.hpp"
#include "entity/simple/Stair.hpp"
#include "entity/simple/Hole.hpp"
#include "entity/simple/Sign.hpp"
#include "entity/button/FileButton.hpp"

#include "util/logger/Logger.hpp"

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

	#include "util/define/DefineLoadEntity.hpp"
		if (false) {}
		LOAD_ENTITY2(Grass, IGridded, IUpdatable)
		LOAD_ENTITY(RoyalMat, IGridded)
		LOAD_ENTITY(BottomWall, IGridded)
		LOAD_ENTITY(UpperWall, IGridded)
		LOAD_ENTITY(RockGround, IGridded)
		LOAD_ENTITY(LeftWall, IGridded)
		LOAD_ENTITY(RightWall, IGridded)
		LOAD_ENTITY(Corner, IGridded)
		LOAD_ENTITY2(FileButton, DrawableTransformable, IInteractable)
		LOAD_ENTITY2(Sign, IGridded, IInteractable)
		LOAD_ENTITY2(Stair, IGridded, IInteractable)
		LOAD_ENTITY2(Hole, IGridded, IInteractable)
	#include "util/define/UndefineLoadEntity.hpp"
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
