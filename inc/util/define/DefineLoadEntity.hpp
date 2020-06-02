#ifndef DEFINE_LOAD_ENTITY_HPP
#define DEFINE_LOAD_ENTITY_HPP

#define LOAD_ENTITY(entity, interface1) \
	else if (stringName == #entity) \
	{ \
		entityContainer.Insert##interface1##Entity( \
			std::make_shared<entity>(x, y, entityContainer.m_pTileMap, element)); \
	}
#define LOAD_ENTITY2(entity, interface1, interface2) \
	else if (stringName == #entity) \
	{ \
		entityContainer.Insert##interface1##interface2##Entity( \
			std::make_shared<entity>(x, y, entityContainer.m_pTileMap, element)); \
		return; \
	}
#define LOAD_ENTITY3(entity, interface1, interface2, interface3) \
	else if (stringName == #entity) \
	{ \
		entityContainer.Insert##interface1##interface2##interface3##Entity( \
			std::make_shared<entity>(x, y, entityContainer.m_pTileMap, element)); \
		return; \
	}
#endif
