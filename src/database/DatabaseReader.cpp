#include "../../inc/database/DatabaseReader.hpp"
#include "../../inc/util/logger/Logger.hpp"

#include <bsoncxx/json.hpp>

#include <string>

using bsoncxx::builder::stream::open_document;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::concatenate_doc;

DatabaseReader::DatabaseReader(
		char const * const database,
		char const * const databaseUrl,
		short const port,
		sf::Vector2u const tileUnitSize,
		unsigned int const tileWidth,
		unsigned int const tileHeight)
	: mk_type("DatabaseReader")
	, mk_inst{}
	, mk_clientConnection({mongocxx::uri(std::string(databaseUrl) + ":" + std::to_string(port))})
	, mk_databaseName(database)
	, m_bottomLayerTileMap(
		tileUnitSize,
		tileWidth,
		tileHeight)
{}

void DatabaseReader::LoadNewRegion(
	char const * const collectionName,
	char const * const subCollectionName)
{
	auto collection = mk_clientConnection[mk_databaseName][std::string(collectionName) + "." + std::string(subCollectionName)];
	auto documents = collection.find({});
	for(auto doc : documents) {
		s_pLogger->DebugLog(mk_type, bsoncxx::to_json(doc).c_str());
	}
}

mongocxx::cursor DatabaseReader::GetRegions_(
	mongocxx::collection& collection,
	std::string const& keyX,
	Range rangeX,
	std::string const& keyY,
	Range rangeY)
{
	document query, conditionX, conditionY;
	UpdateCondition1D_(conditionX, keyX, rangeX);
	UpdateCondition1D_(conditionY, keyY, rangeY);
	CombineConditions_(query, conditionX, conditionY);
	return collection.find(query.view());
}

void DatabaseReader::UpdateCondition1D_(
	document& condition /*in-out*/,
	std::string const key,
	Range range)
{
	condition <<
			key <<
			open_document <<
				"$gte" << range.first <<
				"$lte" << range.second <<
			close_document;
}

void DatabaseReader::CombineConditions_(
		document& combinedCondition /*in-out*/,
		document& firstCondition,
		document& secondCondition)
{
	combinedCondition << "$and" <<
		open_array <<
			open_document << concatenate_doc{firstCondition.view()} << close_document <<
			open_document << concatenate_doc{secondCondition.view()} << close_document <<
		close_array;
}