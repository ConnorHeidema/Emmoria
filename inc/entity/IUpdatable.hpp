#ifndef I_UPDATABLE_HPP
#define I_UPDATABLE_HPP

class IUpdatable
{
public:
	IUpdatable(int x, int y) {}
	virtual void Update() = 0;
	virtual ~IUpdatable() {};
};

#endif
