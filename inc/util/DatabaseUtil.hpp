#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>

#include <bsoncxx/builder/stream/document.hpp>

using bsoncxx::builder::stream::document;
using Range = std::pair<int, int>;
using Coordinate = std::pair<int, int>;

/**
 * A utility class for interacting with a mongodb database
 */
class DatabaseUtil
{
public:
	/**
	 * Gets a region of objects from the mongodb
	 * @param collection The collection to grab the stream from
	 * @param keyX The x key
	 * @param rangeX The range of regions wanted in the x plane
	 * @param keyY The y key
	 * @param rangeY The range of regions wanted in the y plane
	 * @return A cursor to the list of documents that match the criteria
	 */
	static mongocxx::cursor GetRegions_(
		mongocxx::collection& collection,
		std::string const& keyX,
		Range const& rangeX,
		std::string const& keyY,
		Range const& rangeY);

	/**
	 * Creates the query for only getting contrained regions over one dimension
	 * @param condition The condition modified to create this query
	 * @param key The key for the dimension
	 * @param range The range of regions wanted in the dimension
	 */
	static void UpdateCondition1D_(
		document& condition /*in-out*/,
		std::string const& key,
		Range const& range);

	/**
	 * Combines 2 conditions together
	 * @param combinedCondition The combined condition
	 * @param firstCondition The first condition to combine
	 * @param secondCondition The second condition to combine
	 */
	static void CombineConditions_(
			document& combinedCondition /*in-out*/,
			document& firstCondition,
			document& secondCondition);

	static Coordinate GetPositionValueFromKeyDb_(bsoncxx::array::element element, char const * const key);

	/**
	 * Gets the name of the entity
	 * @param element The element the name can be found from
	 * @return The name.
	 */
	static std::string GetStringValueFromKeyDb(bsoncxx::array::element element, char const * const key);
};

#endif
