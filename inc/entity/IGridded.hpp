#ifndef I_GRIDDED_HPP
#define I_GRIDDED_HPP

#include <memory>
/**
 * Includes the components all interactable entities should have.
 * This includes a pointer to where the subtexture is in the
 * texture file
 */
class IGridded
{
public:
	IGridded(int x, int y) : m_xIndex(x), m_yIndex(y) {}

	/**
	 * Gets the index of the subtextureindex.
	 * The subindex is used by the TileMap
	 */
	virtual std::shared_ptr<int> GetSubTextureIndexPtr() = 0;

	int m_xIndex;
	int m_yIndex;

	virtual ~IGridded() {};
};

#endif
