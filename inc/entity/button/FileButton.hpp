#ifndef FILE_BUTTON_HPP
#define FILE_BUTTON_HPP

#include "entity/EntityCombination.hpp"

class FileButton
	: public DrawableTransformableIInteractable
{
public:
	FileButton(int x, int y) : DrawableTransformableIInteractable(x, y) {}

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
