#include "gtest/gtest.h"

#include "domparser/IDOMFactory.h"
#include "domparser/IPageData.h"
#include "domparser/PageDataImpl.h"
#include "domparser/WritePageData.h"
#include "domparser/PageDataFactory.h"

#include <memory>
#include <stdexcept>

TEST(Test1, Valid)
{
    std::shared_ptr<IDOMFactory> ptr(new PageDataFactory);
    std::shared_ptr<IPageData> pageData(ptr->createPageData("index.html"));
    WritePageData writePageData(pageData);
    writePageData.writeToFile();
    std::shared_ptr<IPageData> pageData2(ptr->createPageData("pagedata.html"));

    EXPECT_EQ(pageData->getNumberOfTags(), pageData2->getNumberOfTags());
    EXPECT_EQ(pageData->first()->getTagName(), pageData2->first()->getTagName());
    EXPECT_EQ(pageData->last()->getTagName(), pageData2->last()->getTagName());
}

TEST(Test2, Exception)
{
    std::shared_ptr<IDOMFactory> ptr(new PageDataFactory);
    std::shared_ptr<IPageData> pageData(ptr->createPageData(""));
    WritePageData writePageData(pageData);
    EXPECT_THROW(writePageData.writeToFile(), std::logic_error);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}