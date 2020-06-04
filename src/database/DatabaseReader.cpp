#include "database/DatabaseReader.hpp"

#include "entity/EntityFactory.hpp"

#include "util/logger/Logger.hpp"

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/stdx/string_view.hpp>
#include <bsoncxx/string/to_string.hpp>

#include <string>

DatabaseReader::DatabaseReader(
		char const * const database,
		char const * const databaseUrl,
		short const port)
	: mk_type("DatabaseReader")
	, mk_inst{}
	, mk_clientConnection({mongocxx::uri(std::string(databaseUrl) + ":" + std::to_string(port))})
	, mk_databaseName(database)
{}

void DatabaseReader::LoadNewRegion(
	char const * const collectionName,
	char const * const subCollectionName,
	EntityContainer& entityContainer)
{
	auto qualifiedCollection = subCollectionName != NULL && subCollectionName[0] == '\0' ?
		std::string(collectionName) :
		std::string(collectionName) + "." + std::string(subCollectionName);
	auto collection = mk_clientConnection[mk_databaseName][qualifiedCollection];
	auto documents = collection.find({});

	for (auto doc : documents)
	{
		bsoncxx::document::element allEntities{doc["entities"]};
		auto entitySets = allEntities.get_array().value;
		for (auto entity : entitySets)
		{
			EntityFactory::LoadEntityOntoContainer(entity, entityContainer);
		}
	}
	MapGriddablesToTilemap_(entityContainer, "image/background/Generic.png");
	entityContainer.m_pTileMap->Load();
	entityContainer.InsertDrawableTransformableEntity(entityContainer.m_pTileMap);
}

void DatabaseReader::MapGriddablesToTilemap_(
	EntityContainer& entityContainer,
	std::string const& tilemapName)
{
	entityContainer.m_pTileMap->SetTextureFile(tilemapName);
	for (auto&& gridded : entityContainer.GetGriddedEntities())
	{
		entityContainer.m_pTileMap->PrepareTile(gridded->m_xIndex, gridded->m_yIndex, gridded->GetSubTextureIndexPtr());
	}
}