#include "util/datastructure/QuadTree.hpp"

QuadTree::QuadTree(
	int const& leftBound,
	int const& topBound,
	int const& rightBound,
	int const& bottomBound)
		: m_rootNodePtrList()
		, m_subTrees { nullptr, nullptr, nullptr, nullptr }
		, m_leftBound(leftBound)
		, m_topBound(topBound)
		, m_rightBound(rightBound)
		, m_bottomBound(bottomBound)
		, m_heightMidPoint((topBound + bottomBound) / 2)
		, m_widthMidPoint((leftBound + rightBound) / 2)
		, k_uBreakingNodeSize(8)
{}

std::list<std::shared_ptr<QuadNode>> QuadTree::RetrieveAll()
{
	auto allNodes = std::list<std::shared_ptr<QuadNode>>();
	allNodes.splice(allNodes.end(), m_rootNodePtrList);
	for (unsigned int treeCorner = 0; treeCorner < m_subTrees.size(); treeCorner++)
	{
		if (m_subTrees[treeCorner] && m_subTrees[treeCorner]->m_rootNodePtrList.size() != 0)
		{
			allNodes.splice(allNodes.end(), m_subTrees[treeCorner]->RetrieveAll());
		}
	}
	return allNodes;
}

std::list<std::shared_ptr<QuadNode>> QuadTree::Retrieve(int const& left, int const& top, int const& right, int const& bottom)
{
	std::list<std::shared_ptr<QuadNode>> returnedNodes;
	for (auto& node : m_rootNodePtrList)
	{
		bool leftInside = left >= node->m_left && left < node->m_right;
		bool topInside = top >= node->m_top && top < node->m_bottom;
		bool rightInside = right >= node->m_left && right < node->m_right;
		bool bottomInside = bottom >= node->m_top && bottom < node->m_bottom;
		if ((leftInside && topInside) ||
			(topInside && rightInside) ||
			(rightInside && bottomInside) ||
			(bottomInside && leftInside))
		{
			returnedNodes.emplace_back(node);
		}
	}
	if (left < m_widthMidPoint)
	{
		if (top < m_heightMidPoint && m_subTrees[TOP_LEFT])
		{
			returnedNodes.splice(
				returnedNodes.end(),
				m_subTrees[TOP_LEFT]->Retrieve(left, top, right, bottom));
		}
		if (bottom > m_heightMidPoint && m_subTrees[BOTTOM_LEFT])
		{
			returnedNodes.splice(
				returnedNodes.end(),
				m_subTrees[BOTTOM_LEFT]->Retrieve(left, top, right, bottom));
		}
	}
	if (right > m_widthMidPoint)
	{
		if (top < m_heightMidPoint && m_subTrees[TOP_RIGHT])
		{
			returnedNodes.splice(
				returnedNodes.end(),
				m_subTrees[TOP_RIGHT]->Retrieve(left, top, right, bottom));
		}
		if (bottom > m_heightMidPoint && m_subTrees[BOTTOM_RIGHT])
		{
			returnedNodes.splice(
				returnedNodes.end(),
				m_subTrees[BOTTOM_RIGHT]->Retrieve(left, top, right, bottom));
		}
	}
	return returnedNodes;
}

void QuadTree::emplace_front(std::shared_ptr<QuadNode> pQuadNode)
{
	if (m_rootNodePtrList.size() < k_uBreakingNodeSize)
	{
		m_rootNodePtrList.emplace_front(pQuadNode);
		return;
	}

	if (pQuadNode->m_left > m_leftBound &&
		pQuadNode->m_top > m_topBound &&
		pQuadNode->m_right < m_widthMidPoint &&
		pQuadNode->m_bottom < m_heightMidPoint)
	{
		if (!m_subTrees[TOP_LEFT])
		{
			m_subTrees[TOP_LEFT] = std::make_unique<QuadTree>(
				m_leftBound,
				m_topBound,
				m_widthMidPoint,
				m_heightMidPoint);
		}
		m_subTrees[TOP_LEFT]->emplace_front(pQuadNode);
	}
	else if (pQuadNode->m_left > m_widthMidPoint &&
		pQuadNode->m_top > m_topBound &&
		pQuadNode->m_right < m_rightBound &&
		pQuadNode->m_bottom < m_heightMidPoint)
	{
		if (!m_subTrees[TOP_RIGHT])
		{
			m_subTrees[TOP_RIGHT] = std::make_unique<QuadTree>(
				m_widthMidPoint,
				m_topBound,
				m_rightBound,
				m_heightMidPoint);
		}
		m_subTrees[TOP_RIGHT]->emplace_front(pQuadNode);
	}
	else if (pQuadNode->m_left > m_widthMidPoint &&
		pQuadNode->m_top > m_heightMidPoint &&
		pQuadNode->m_right < m_rightBound &&
		pQuadNode->m_bottom < m_bottomBound)
	{
		if (!m_subTrees[BOTTOM_RIGHT])
		{
			m_subTrees[BOTTOM_RIGHT] = std::make_unique<QuadTree>(
				m_widthMidPoint,
				m_heightMidPoint,
				m_rightBound,
				m_bottomBound);
		}
		m_subTrees[BOTTOM_RIGHT]->emplace_front(pQuadNode);
	}
	else if (pQuadNode->m_left > m_leftBound &&
		pQuadNode->m_top > m_heightMidPoint &&
		pQuadNode->m_right < m_widthMidPoint &&
		pQuadNode->m_bottom < m_bottomBound)
	{
		if (!m_subTrees[BOTTOM_LEFT])
		{
			m_subTrees[BOTTOM_LEFT] = std::make_unique<QuadTree>(
				m_leftBound,
				m_heightMidPoint,
				m_widthMidPoint,
				m_bottomBound);
		}
		m_subTrees[BOTTOM_LEFT]->emplace_front(pQuadNode);
	}
}

bool QuadTree::Remove(int const& id)
{
	for (auto nodeIter = m_rootNodePtrList.begin();
		 nodeIter != m_rootNodePtrList.end();
		 nodeIter++)
	{
		if (id == (*nodeIter)->m_id)
		{
			m_rootNodePtrList.remove(*nodeIter);
			return true;
		}
	}
	if ((m_subTrees[TOP_LEFT] && m_subTrees[TOP_LEFT]->Remove(id)) ||
		(m_subTrees[TOP_RIGHT] && m_subTrees[TOP_RIGHT]->Remove(id)) ||
		(m_subTrees[BOTTOM_RIGHT] && m_subTrees[BOTTOM_RIGHT]->Remove(id)) ||
		(m_subTrees[BOTTOM_LEFT] && m_subTrees[BOTTOM_LEFT]->Remove(id)))
	{
		for (unsigned int treeCorner = 0; treeCorner < m_subTrees.size(); treeCorner++)
		{
			if (m_subTrees[treeCorner] && m_subTrees[treeCorner]->m_rootNodePtrList.size() == 0)
			{
				m_subTrees[treeCorner] = nullptr;
			}
		}
		return true;
	}
	return false;
}

void QuadTree::Clear()
{
	for (unsigned int treeCorner = 0; treeCorner < m_subTrees.size(); treeCorner++)
	{
		if (m_subTrees[treeCorner] && m_subTrees[treeCorner]->m_rootNodePtrList.size() == 0)
		{
			m_subTrees[treeCorner]->Clear();
			m_subTrees[treeCorner] = nullptr;
		}
	}
	m_rootNodePtrList.clear();
}
