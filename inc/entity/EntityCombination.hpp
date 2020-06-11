#ifndef ENTITY_COMBINATION_HPP
#define ENTITY_COMBINATION_HPP

#include "entity/DrawableTransformable.hpp"
#include "entity/IGridded.hpp"
#include "entity/IInteractable.hpp"
#include "entity/IUpdatable.hpp"

#include "entity/SharedParameters.hpp"

#include "map/TileMap.hpp"

/**
 * This file defines all the classes that may be mixed for entities
 * all entities should share from only 1 base interface of the 4 types
 * above
 */
#define CLASS(firstInterface, secondInterface) \
	class firstInterface##secondInterface \
		: public firstInterface \
		, public secondInterface \
		{ public: \
		firstInterface##secondInterface(std::shared_ptr<SharedParameters> pSharedParameters, std::shared_ptr<TileMap> pTileMap) \
		: firstInterface(pSharedParameters, pTileMap) \
		, secondInterface(pSharedParameters, pTileMap) \
		{} \
		virtual ~firstInterface##secondInterface() {}; }

	CLASS(DrawableTransformable, IGridded);
	CLASS(DrawableTransformable, IInteractable);
	CLASS(DrawableTransformable, IUpdatable);
	CLASS(IGridded, IInteractable);
	CLASS(IGridded, IUpdatable);
	CLASS(IInteractable, IUpdatable);

#undef CLASS
#define CLASS(firstInterface, secondInterface, thirdInterface) \
	class firstInterface##secondInterface##thirdInterface \
		: public firstInterface \
		, public secondInterface \
		, public thirdInterface \
		{ public:\
		firstInterface##secondInterface##thirdInterface(std::shared_ptr<SharedParameters> pSharedParameters, std::shared_ptr<TileMap> pTileMap) \
		: firstInterface(pSharedParameters, pTileMap) \
		, secondInterface(pSharedParameters, pTileMap) \
		, thirdInterface(pSharedParameters, pTileMap) \
		{} \
			 virtual ~firstInterface##secondInterface##thirdInterface() {}; }

	CLASS(DrawableTransformable, IGridded, IInteractable);
	CLASS(DrawableTransformable, IGridded, IUpdatable);
	CLASS(DrawableTransformable, IInteractable, IUpdatable);
	CLASS(IGridded, IInteractable, IUpdatable);

#undef CLASS

#endif
