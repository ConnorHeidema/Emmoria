#ifndef RETURNABLE_HPP
#define RETURNABLE_HPP

#include <tuple>
#include <memory>

class EntityContainer;

/**
 * The returnable consists of everything an interaction or update can provide back
 * to the base gameloop. This may include changing what is currently loaded in
 */
class Returnable
{
public:
	Returnable() : position(-1,-1), collection(""), subCollection(""), updated(false) {}
	std::pair<int, int> position;
	std::string collection;
	std::string subCollection;
	bool updated = false;

	std::shared_ptr<EntityContainer> m_pNewStartingEntityContainer;
};
#endif
