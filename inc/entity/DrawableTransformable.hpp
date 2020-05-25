#ifndef DRAWABLE_TRANSFORMABLE_HPP
#define DRAWABLE_TRANSFORMABLE_HPP

#include <SFML/Graphics.hpp>

class DrawableTransformable
	: public sf::Drawable
	, public sf::Transformable
{
public:
	DrawableTransformable(int x, int y) {};
	virtual ~DrawableTransformable() {};
};

#endif
