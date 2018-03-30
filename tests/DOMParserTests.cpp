#include "gtest/gtest.h"
#include "DOMParser.h"
#include "Teg.h"

TEST(ClassTeg, EmptyClass)
{
	Teg someTeg;

	std::string name = someTeg.getTegName();
	std::string parent = someTeg.getParent();
	std::vector<std::string> children = someTeg.getChildren();
	std::vector<std::pair<std::string, std::string>> tegProperties = someTeg.getTegProperties();
	std::string content = someTeg.getContent();

	EXPECT_TRUE(name.empty());
	EXPECT_TRUE(parent.empty());
	EXPECT_TRUE(children.empty());
	EXPECT_TRUE(tegProperties.empty());
	EXPECT_TRUE(content.empty());
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}