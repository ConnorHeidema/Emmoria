#ifndef GRASS_HPP
#define GRASS_HPP

#include "entity/EntityCombination.hpp"

#include <memory>

/**
 * The class represent a patch of grass and its interactable properties
 */
class Grass
	: public IGriddedIUpdatable
{
public:
	Grass(int x, int y) :
		IGriddedIUpdatable(x, y),
		m_ptmp(std::make_shared<int>(0)),
		m_currentFrame(0),
		m_cyclicFrame(120),
		m_numAnimations(4)
	{}
	virtual ~Grass() {};

	void Update() override;
	std::shared_ptr<int> GetSubTextureIndexPtr() override;
private:
	std::shared_ptr<int> m_ptmp;
	int m_currentFrame;
	int m_cyclicFrame;
	int m_numAnimations;
};

#endif
