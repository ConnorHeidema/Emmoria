#include "../../../inc/entity/simple/Grass.hpp"
#include <iostream>

void Grass::Update()
{
	m_currentFrame = (m_currentFrame + 1) % m_cyclicFrame;
	(*m_ptmp) = m_currentFrame / (m_cyclicFrame / m_numAnimations);
}

std::shared_ptr<int> Grass::GetSubTextureIndexPtr()
{
	return m_ptmp;
}
