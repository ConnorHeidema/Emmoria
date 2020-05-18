#ifndef I_INTERACTABLE_ENTITY_HPP
#define I_INTERACTABLE_ENTITY_HPP

#include <memory>
/**
 * Includes the components all interactable entities should have.
 * This includes a pointer to where the subtexture is in the
 * texture file
 */
class IInteractableEntity
{
public:
	/**
	 * Gets the index of the subtextureindex.
	 * The subindex is used by the TileMap
	 */
	virtual std::shared_ptr<int> GetSubTextureIndexPtr() = 0;
	virtual ~IInteractableEntity() {};
};

#endif
