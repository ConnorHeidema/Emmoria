#include "entity/simple/Hole.hpp"

#include "util/logger/Logger.hpp"

Hole::Hole(
	std::shared_ptr<SharedParameters> pSharedParameters,
	std::shared_ptr<TileMap> pTileMap,
	bsoncxx::array::element element)
		: IGriddedIInteractable(pSharedParameters, pTileMap)
{
	s_pLogger->DebugLog(LoggerType_t("Hole"), (std::string("Hole with shared parameters") + std::to_string(pSharedParameters->m_left)).c_str());
}

std::shared_ptr<int> Hole::GetSubTextureIndexPtr()
{
	return std::make_shared<int>(11);
}
