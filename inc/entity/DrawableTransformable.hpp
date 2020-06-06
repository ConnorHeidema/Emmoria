#ifndef DRAWABLE_TRANSFORMABLE_HPP
#define DRAWABLE_TRANSFORMABLE_HPP

#include "entity/Entity.hpp"

#include <SFML/Graphics.hpp>

#include <bsoncxx/builder/stream/document.hpp>

#include <memory>

class TileMap;

class DrawableTransformable
	: public sf::Drawable
	, public sf::Transformable
	, public Entity
{
public:
	DrawableTransformable(int x, int y, std::shared_ptr<TileMap> /*pTileMap*/) {};
	virtual ~DrawableTransformable() {};
};

#endif
