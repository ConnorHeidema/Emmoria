#include "../../inc/entity/DrawableTransformable.hpp"
#include "../../inc/entity/IGridded.hpp"
#include "../../inc/entity/IInteractable.hpp"
#include "../../inc/entity/IUpdatable.hpp"

#ifndef ENTITY_COMBINATION_HPP
#define ENTITY_COMBINATION_HPP

/**
 * This file defines all the classes that may be mixed for entities
 * all entities should share from only 1 base interface of the 4 types
 * above
 */
#define CLASS(firstInterface, secondInterface) \
	class firstInterface##secondInterface \
		: public firstInterface \
		, public secondInterface \
		{ public: virtual ~firstInterface##secondInterface() {}; }

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
		{ public: virtual ~firstInterface##secondInterface##thirdInterface() {}; }

	CLASS(DrawableTransformable, IGridded, IInteractable);
	CLASS(DrawableTransformable, IGridded, IUpdatable);
	CLASS(DrawableTransformable, IInteractable, IUpdatable);
	CLASS(IGridded, IInteractable, IUpdatable);

#undef CLASS

class DrawableTransformableIGriddedIInteractableIUpdatable
		: public DrawableTransformable
		, public IGridded
		, public IInteractable
		, public IUpdatable
		{ public: virtual ~DrawableTransformableIGriddedIInteractableIUpdatable() {}; };

#endif
