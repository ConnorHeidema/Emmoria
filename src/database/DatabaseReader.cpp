#include "../../inc/database/DatabaseReader.hpp"

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
	char const * const subCollectionName)
{
	auto collection = mk_clientConnection[mk_databaseName][std::string(collectionName) + std::string(subCollectionName)];
}