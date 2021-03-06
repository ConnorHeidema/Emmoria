#include "entity/player/Player.hpp"
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

#include "entity/SharedParameters.hpp"

#include "util/DatabaseUtil.hpp"
#include "util/logger/Logger.hpp"

#include <vector>
#include <sstream>

void EntityFactory::LoadEntityOntoContainer(
	bsoncxx::array::element element,
	std::shared_ptr<EntityContainer> pEntityContainer)
{
	std::shared_ptr<SharedParameters> pEntitySharedParameters = std::make_shared<SharedParameters>();
	auto stringName = DatabaseUtil::GetStringValueFromKeyDb(element, "name");
	bsoncxx::document::element indexObject{element["index"]};
	if (indexObject.length() != 0)
	{
		Coordinate coordinate = DatabaseUtil::GetPositionValueFromKeyDb_(element, "index");
		int x = coordinate.first;
		int y = coordinate.second;

		pEntitySharedParameters->m_left = x * 120;
		pEntitySharedParameters->m_top = y * 120;
		pEntitySharedParameters->m_right = (x + 1) * 120;
		pEntitySharedParameters->m_bottom = (y + 1) * 120;
	}
	bsoncxx::document::element positionObject{element["position"]};
	if (positionObject.length() != 0)
	{
		Coordinate coordinate = DatabaseUtil::GetPositionValueFromKeyDb_(element, "position");
		int x = coordinate.first;
		int y = coordinate.second;
		pEntitySharedParameters->m_left = x;
		pEntitySharedParameters->m_top = y;
		pEntitySharedParameters->m_right = x + 120;
		pEntitySharedParameters->m_bottom = y + 120;
	}
	#include "util/define/DefineLoadEntity.hpp"
		if (false) {}
		LOAD_ENTITY(RoyalMat, IGridded)
		LOAD_ENTITY(BottomWall, IGridded)
		LOAD_ENTITY(UpperWall, IGridded)
		LOAD_ENTITY(RockGround, IGridded)
		LOAD_ENTITY(LeftWall, IGridded)
		LOAD_ENTITY(RightWall, IGridded)
		LOAD_ENTITY(Corner, IGridded)
		LOAD_ENTITY2(Grass, IGridded, IUpdatable)
		LOAD_ENTITY2(FileButton, DrawableTransformable, IUpdatable)
		LOAD_ENTITY2(Sign, IGridded, IInteractable)
		LOAD_ENTITY2(Stair, IGridded, IInteractable)
		LOAD_ENTITY2(Hole, IGridded, IInteractable)
		LOAD_ENTITY3(Player, DrawableTransformable, IInteractable, IUpdatable)
	#include "util/define/UndefineLoadEntity.hpp"
}