#include <gtest/gtest.h>
#include "DOMParser.h"

TEST(DOMParserTest, GetTegName)
{
	std::string testData("tegName");
	std::string answer("tegName");
	DOMParser obj;

	std::string result = obj.getTegName(testData);

	EXPECT_EQ(result, answer);

}
