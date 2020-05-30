#ifndef FILE_BUTTON_HPP
#define FILE_BUTTON_HPP

#include "entity/EntityCombination.hpp"

class FileButton
	: public DrawableTransformableIInteractable
{
public:
	FileButton(int x, int y, std::shared_ptr<TileMap> pTileMap) : DrawableTransformableIInteractable(x, y, pTileMap) {}

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
