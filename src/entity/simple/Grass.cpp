#include <entity/simple/Grass.hpp>

Grass::Grass(
	int x,
	int y,
	std::shared_ptr<TileMap> pTileMap,
	bsoncxx::array::element element)
		: IGriddedIUpdatable(x, y, pTileMap)
		, m_ptmp(std::make_shared<int>(0))
		, m_currentFrame(0)
		, m_cyclicFrame(120)
		, m_numAnimations(4)
{}

Grass::~Grass() {}

Returnable Grass::Update()
{
	m_currentFrame = (m_currentFrame + 1) % m_cyclicFrame;
	(*m_ptmp) = m_currentFrame / (m_cyclicFrame / m_numAnimations);
	NotifyObservers();
	return Returnable();
}

std::shared_ptr<int> Grass::GetSubTextureIndexPtr()
{
	return m_ptmp;
}
