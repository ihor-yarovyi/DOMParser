#include "gtest/gtest.h"
#include "BaseParser.h"
#include "TegNameParser.h"
#include <AttributeParser.h>

#include <memory>

TEST(ParserNameTeg, ValidCase)
{
    std::string inputData("<html><head><Title>Caption</Title></head></html>");
    std::vector<std::string> expectResult;
    expectResult.emplace_back("html");
    expectResult.emplace_back("head");
    expectResult.emplace_back("Title");

    std::shared_ptr<BaseParser> ptr = std::make_shared<TegNameParser>(inputData);

    std::vector<std::string> result = ptr->parse();

    EXPECT_EQ(expectResult[0], result[0]);
    EXPECT_EQ(expectResult[1], result[1]);
    EXPECT_EQ(expectResult[2], result[2]);
    EXPECT_EQ(result.size(), 3);
}

TEST(ParserNameTeg, InvalidCase)
{
    std::string inputData("html>head><Title>Caption</Title></head></html>");
    std::vector<std::string> expectResult;
    expectResult.emplace_back("Title");
    std::shared_ptr<BaseParser> ptr = std::make_shared<TegNameParser>(inputData);

    std::vector<std::string> result = ptr->parse();

    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(expectResult[0], result[0]);
}

TEST(ParserNameTeg, InvalidCase2)
{
    std::string inputData("<SomeData<Something");
    std::shared_ptr<BaseParser> ptr = std::make_shared<TegNameParser>(inputData);

    std::vector<std::string> result = ptr->parse();

    EXPECT_TRUE(result.empty());
}


int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
