#ifndef FILE_BUTTON_HPP
#define FILE_BUTTON_HPP

#include "entity/EntityCombination.hpp"
#include "util/logger/Logger.hpp"

class FileButton
	: public DrawableTransformableIInteractable
{
public:
	FileButton(int x, int y, std::shared_ptr<TileMap> pTileMap) : DrawableTransformableIInteractable(x, y, pTileMap),
		mk_type("FileButton")
	{
		s_pLogger->ErrorLog(mk_type, "Creating FileButton");
	}

private:
	LoggerType_t const mk_type;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
