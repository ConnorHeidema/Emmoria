#ifndef QUAD_NODE
#define QUAD_NODE

#include "entity/SharedParameters.hpp"

#include <memory>

static int entityId = 0;

class QuadNode
{
public:
	QuadNode(std::shared_ptr<SharedParameters> pSharedParameters)
		: m_id(entityId++)
		, m_left(pSharedParameters->m_left)
		, m_top(pSharedParameters->m_top)
		, m_right(pSharedParameters->m_right)
		, m_bottom(pSharedParameters->m_bottom)
	{};

	int m_id;
	int m_left;
	int m_top;
	int m_right;
	int m_bottom;
private:

};

#endif