#ifndef I_INTERACTABLE_ENTITY_HPP
#define I_INTERACTABLE_ENTITY_HPP

#include <memory>

class IInteractableEntity
{
public:
	virtual std::shared_ptr<int> GetSubTextureIndexPtr() { return std::make_shared<int>(5);};
	std::shared_ptr<int> m_subTextureIndex;
private:
};

#endif
