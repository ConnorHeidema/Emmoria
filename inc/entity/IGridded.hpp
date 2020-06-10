#ifndef I_GRIDDED_HPP
#define I_GRIDDED_HPP

#include "entity/Entity.hpp"

#include "map/TileMap.hpp"
#include "util/observer/IGriddedSubject.hpp"

#include <bsoncxx/builder/stream/document.hpp>

#include <memory>
/**
 * Includes the components all interactable entities should have.
 * This includes a pointer to where the subtexture is in the
 * texture file
 */
class IGridded
	: public IGriddedSubject
	, public Entity
{
public:
	IGridded(int x, int y, std::shared_ptr<TileMap> pTileMap) : IGriddedSubject(x, y) { RegisterObserver(pTileMap); }

	/**
	 * Gets the index of the subtextureindex.
	 * The subindex is used by the TileMap
	 */
	virtual std::shared_ptr<int> GetSubTextureIndexPtr() = 0;

	virtual ~IGridded() {};
};

#endif
