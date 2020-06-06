#ifndef ENTITY_HPP
#define ENTITY_HPP

class Entity
{
public:
	Entity();
	virtual bool ShouldBeDeleted();
	virtual ~Entity();
};

#endif
