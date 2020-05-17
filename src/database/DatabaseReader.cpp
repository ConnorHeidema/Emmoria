#include "../../inc/database/DatabaseReader.hpp"

#include <string>

DatabaseReader::DatabaseReader(char const * const databaseUrl,
		short const port)
	: mk_type("DatabaseReader")
	, mk_inst{}
	, mk_clientConnection({mongocxx::uri(std::string(databaseUrl) + ":" + std::to_string(port))})
{}