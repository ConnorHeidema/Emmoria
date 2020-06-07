#include "util/DatabaseUtil.hpp"

#include "util/logger/Logger.hpp"

using bsoncxx::builder::stream::open_document;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::concatenate_doc;

mongocxx::cursor DatabaseUtil::GetRegions_(
	mongocxx::collection& collection,
	std::string const& keyX,
	Range const& rangeX,
	std::string const& keyY,
	Range const& rangeY)
{
	document query, conditionX, conditionY;
	UpdateCondition1D_(conditionX, keyX, rangeX);
	UpdateCondition1D_(conditionY, keyY, rangeY);
	CombineConditions_(query, conditionX, conditionY);
	return collection.find(query.view());
}

void DatabaseUtil::UpdateCondition1D_(
	document& condition /*in-out*/,
	std::string const& key,
	Range const& range)
{
	condition <<
			key <<
			open_document <<
				"$gte" << range.first <<
				"$lte" << range.second <<
			close_document;
}

void DatabaseUtil::CombineConditions_(
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

Coordinate DatabaseUtil::GetPositionValueFromKeyDb_(bsoncxx::array::element element, char const * const key)
{
	bsoncxx::document::element position{element[key]};
	bsoncxx::document::element xPositionElement{position["x"]};
	int xIndex = xPositionElement.get_int32();
	bsoncxx::document::element yPositionElement{position["y"]};
	int yIndex = yPositionElement.get_int32();
	return Coordinate(xIndex, yIndex);
}

std::string DatabaseUtil::GetStringValueFromKeyDb(
	bsoncxx::array::element element,
	char const * const key)
{
	bsoncxx::document::element entityName{element[key]};
	auto entityNameValue = entityName.get_utf8().value;
	return entityNameValue.to_string();
}
