#include "entity/SharedParameters.hpp"

SharedParameters::SharedParameters()
	: m_left(-1)
	, m_top(-1)
	, m_right(-1)
	, m_bottom(-1)
{}

SharedParameters::SharedParameters(
	int left,
	int top,
	int right,
	int bottom)
	: m_left(left)
	, m_top(top)
	, m_right(right)
	, m_bottom(bottom)
{}