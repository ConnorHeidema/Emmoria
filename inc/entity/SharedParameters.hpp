#ifndef SHARED_PARAMETERS_HPP
#define SHARED_PARAMETERS_HPP

/**
 * Shared parameters are shared by all loaded objects from the database.
 */
class SharedParameters
{
public:
	SharedParameters();
	SharedParameters(
		int left,
		int top,
		int right,
		int bottom);
	int m_left;
	int m_top;
	int m_right;
	int m_bottom;
};

#endif
