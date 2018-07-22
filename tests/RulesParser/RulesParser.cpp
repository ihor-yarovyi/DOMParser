#include "gtest/gtest.h"

#include "domparser/CheckRulesFactory.h"
#include "domparser/Tag.h"

#include <memory>

TEST(SelectAllRule, ValidCase)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("*"));
    std::unique_ptr<Tag> tag(new Tag);

    EXPECT_TRUE(ptr->checkRules(tag.get()));
}

TEST(SelectAllRule, BadRule)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("&"));

    EXPECT_EQ(ptr.get(), nullptr);
}

TEST(SelectDivRule, ValidCase)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("div"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");

    EXPECT_TRUE(ptr->checkRules(tag.get()));
}

TEST(SelectDivRule, AnotherTagName)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("div"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("html");

    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectDivRule, AnotherTagName2)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("div"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("divhtml");

    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectDivRule, BadTag)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("div"));
    Tag* tag = nullptr;
    EXPECT_FALSE(ptr->checkRules(tag));
}

TEST(SelectAllWithAttribute, ValidCase)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[width]"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("size");
    tag->setAttributeTag("class");
    tag->setAttributeTag("width");

    EXPECT_TRUE(ptr->checkRules(tag.get()));
}

TEST(SelectAllWithAttribute, ValidCase2)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[class]"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("size");
    tag->setAttributeTag("class");
    tag->setAttributeTag("width");

    EXPECT_TRUE(ptr->checkRules(tag.get()));
}

TEST(SelectAllWithAttribute, ValidCase3)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[size]"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("size");
    tag->setAttributeTag("class");
    tag->setAttributeTag("width");

    EXPECT_TRUE(ptr->checkRules(tag.get()));
}

TEST(SelectAllWithAttribute, AnotherAttribute)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[id]"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("size");
    tag->setAttributeTag("class");
    tag->setAttributeTag("width");

    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectAllWithAttribute, BadRule)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("id"));
    EXPECT_EQ(ptr.get(), nullptr);
}

TEST(SelectAllWithAttribute, BadTag)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[id]"));
    Tag* tag = nullptr;

    EXPECT_FALSE(ptr->checkRules(tag));
}

TEST(SelectAllWithAttributeAndValue, ValidCase)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[size='2']"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("body");
    tag->setAttributeTag("size");
    tag->setAttributeValueTag("2");
    tag->setAttributeTag("width");
    tag->setAttributeValueTag("10");

    EXPECT_TRUE(ptr->checkRules(tag.get()));
}

TEST(SelectAllWithAttributeAndValue, BadAttributeValue)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[size='5']"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("body");
    tag->setAttributeTag("size");
    tag->setAttributeValueTag("2");
    tag->setAttributeTag("width");
    tag->setAttributeValueTag("10");

    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectAllWithAttributeAndValue, BadRule)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[size'5']"));
    EXPECT_EQ(ptr, nullptr);
}

TEST(SelectAllWithAttributeAndValue, BadTag)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[size='5']"));
    Tag* tag = nullptr;
    EXPECT_FALSE(ptr->checkRules(tag));
}

TEST(SelectAllWithEndString, ValidCase)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[size$='.png']"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("body");
    tag->setAttributeTag("size");
    tag->setAttributeValueTag("picture.png");
    tag->setAttributeTag("width");
    tag->setAttributeValueTag("10");

    EXPECT_TRUE(ptr->checkRules(tag.get()));
}

TEST(SelectAllWithEndString, BadRule)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[size$='png']"));
    EXPECT_EQ(ptr, nullptr);
}

TEST(SelectAllWithEndString, AnotherEndString)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[size$='.png']"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("body");
    tag->setAttributeTag("size");
    tag->setAttributeValueTag("picture.gif");
    tag->setAttributeTag("width");
    tag->setAttributeValueTag("10");

    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectAllWithEndString, BadTag)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[size$='.png']"));
    Tag* tag = nullptr;
    EXPECT_FALSE(ptr->checkRules(tag));
}

TEST(SelectAllWithEndString, BadEndString)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[size$='.gif']"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("body");
    tag->setAttributeTag("size");
    tag->setAttributeValueTag("pictu.gifsdf");
    tag->setAttributeTag("width");
    tag->setAttributeValueTag("10");

    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectAllNotEqualAttributeValue, ValidCase)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[size!='picture.png']"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("body");
    tag->setAttributeTag("size");
    tag->setAttributeValueTag("some.gif");
    tag->setAttributeTag("width");
    tag->setAttributeValueTag("10");

    EXPECT_TRUE(ptr->checkRules(tag.get()));
}

TEST(SelectAllNotEqualAttributeValue, ValidCase1)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[size!='picture.png']"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("body");
    tag->setAttributeTag("size");
    tag->setAttributeValueTag("picture1.png");
    tag->setAttributeTag("width");
    tag->setAttributeValueTag("10");

    EXPECT_TRUE(ptr->checkRules(tag.get()));
}

TEST(SelectAllNotEqualAttributeValue, ValidCase2)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[class!='name']"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("body");
    tag->setAttributeTag("size");
    tag->setAttributeValueTag("picture1.png");
    tag->setAttributeTag("width");
    tag->setAttributeValueTag("10");

    EXPECT_TRUE(ptr->checkRules(tag.get()));
}

TEST(SelectAllNotEqualAttributeValue, InvalidCase)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[size!='some.gif']"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("body");
    tag->setAttributeTag("size");
    tag->setAttributeValueTag("some.gif");
    tag->setAttributeTag("width");
    tag->setAttributeValueTag("10");

    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectAllNotEqualAttributeValue, BadTag)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[size!='some.gif']"));
    Tag* tag = nullptr;
    EXPECT_FALSE(ptr->checkRules(tag));
}

TEST(SelectAllWithBeginString, ValidCase)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[class^='name']"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("nameClass");
    tag->setAttributeTag("size");
    tag->setAttributeValueTag("picture1.png");
    tag->setAttributeTag("width");
    tag->setAttributeValueTag("10");

    EXPECT_TRUE(ptr->checkRules(tag.get()));
}

TEST(SelectAllWithBeginString, PartAttributeValueInTheEndString)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[class^='name']"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("classname");
    tag->setAttributeTag("size");
    tag->setAttributeValueTag("picture1.png");
    tag->setAttributeTag("width");
    tag->setAttributeValueTag("10");

    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectAllWithBeginString, PartAttributeValueInTheMiddleString)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[class^='name']"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("somenameClass");
    tag->setAttributeTag("size");
    tag->setAttributeValueTag("picture1.png");
    tag->setAttributeTag("width");
    tag->setAttributeValueTag("10");

    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectAllWithBeginString, BadTag)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[class^='name']"));
    Tag* tag = nullptr;
    EXPECT_FALSE(ptr->checkRules(tag));
}

TEST(SelectAllWithPartString, ValidCase)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[class*='name']"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("nameClass");

    EXPECT_TRUE(ptr->checkRules(tag.get()));
}

TEST(SelectAllWithPartString, ValidCase2)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[class*='name']"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("Classname");

    EXPECT_TRUE(ptr->checkRules(tag.get()));
}

TEST(SelectAllWithPartString, ValidCase3)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[class*='name']"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("somenameClass");

    EXPECT_TRUE(ptr->checkRules(tag.get()));
}

TEST(SelectAllWithPartString, BadAttributeValue)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[class*='value']"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("nameClass");

    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectAllWithPartString, BadTag)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[class*='name']"));
    Tag* tag = nullptr;
    EXPECT_FALSE(ptr->checkRules(tag));
}

TEST(SelectTagsWithMatchingAttributes, ValidCase)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[class=\"name\"],[size=\"2\"],[width=\"10\"]"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("name");
    tag->setAttributeTag("size");
    tag->setAttributeValueTag("2");
    tag->setAttributeTag("width");
    tag->setAttributeValueTag("10");

    EXPECT_TRUE(ptr->checkRules(tag.get()));
}

TEST(SelectTagsWithMatchingAttributes, ValidCase2)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[class=\"name\"],[size=\"2\"],[width=\"10\"]"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("strnamestr");
    tag->setAttributeTag("size");
    tag->setAttributeValueTag("527");
    tag->setAttributeTag("width");
    tag->setAttributeValueTag("451089");

    EXPECT_TRUE(ptr->checkRules(tag.get()));
}

TEST(SelectTagsWithMatchingAttributes, ValidCase3)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[class=\"name\"],[size=\"2\"]"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("strnamestr");
    tag->setAttributeTag("size");
    tag->setAttributeValueTag("527");
    tag->setAttributeTag("width");
    tag->setAttributeValueTag("451089");

    EXPECT_TRUE(ptr->checkRules(tag.get()));
}

TEST(SelectTagsWithMatchingAttributes, NotEnoughAttribute)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[class=\"name\"],[size=\"2\"],[width=\"10\"]"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("strnamestr");
    tag->setAttributeTag("size");
    tag->setAttributeValueTag("527");

    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectTagsWithMatchingAttributes, NotEnoughAttribute2)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[class=\"name\"],[size=\"2\"],[width=\"10\"]"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("strnamestr");
    tag->setAttributeTag("width");
    tag->setAttributeValueTag("451089");

    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectTagsWithMatchingAttributes, BadTag)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[class=\"name\"],[size=\"2\"],[width=\"10\"]"));
    Tag* tag = nullptr;
    EXPECT_FALSE(ptr->checkRules(tag));
}

TEST(SelectTagsWithMatchingAttributes, BadAttributeValue)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("[class=\"name\"],[size=\"2\"],[width=\"10\"]"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("strnmestr");
    tag->setAttributeTag("width");
    tag->setAttributeValueTag("4589");

    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectSpecificTagWithSpecifiedAttribute, ValidCase)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("p[class=\"name\"]"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("p");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("name");
    tag->setAttributeTag("width");
    tag->setAttributeValueTag("10");

    EXPECT_TRUE(ptr->checkRules(tag.get()));
}

TEST(SelectSpecificTagWithSpecifiedAttribute, AnotherAttributeAndValue)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("p[size=\"2\"]"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("p");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("name");
    tag->setAttributeTag("width");
    tag->setAttributeValueTag("10");

    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectSpecificTagWithSpecifiedAttribute, AnotherTagName)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("p[class=\"name\"]"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("name");
    tag->setAttributeTag("width");
    tag->setAttributeValueTag("10");

    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectSpecificTagWithSpecifiedAttribute, AnotherAttributeValue)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("p[class=\"name\"]"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("p");
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("par");

    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectSpecificTagWithSpecifiedAttribute, AnotherAttributeName)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("p[class=\"name\"]"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("p");
    tag->setAttributeTag("id");
    tag->setAttributeValueTag("name");

    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectChildrenTagWithAttribute, ValidCase)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("div[id=\"wrap\"][class=\"part1\"]"));

    std::unique_ptr<Tag> parentTag(new Tag);
    parentTag->setTagName("div");
    parentTag->setAttributeTag("id");
    parentTag->setAttributeValueTag("wrap");

    std::unique_ptr<Tag> tag(new Tag);
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("part1");
    tag->setParent(parentTag.get());

    EXPECT_TRUE(ptr->checkRules(tag.get()));
}

TEST(SelectChildrenTagWithAttribute, WrongRule)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("div[id=\"wrap\"][class=\"part1\"][class=\"sdf\"]"));
    EXPECT_EQ(ptr, nullptr);
}

TEST(SelectChildrenTagWithAttribute, MixAttributeAndValue)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("div[id=\"wrap\"][class=\"part1\"]"));
    std::unique_ptr<Tag> parentTag(new Tag);
    parentTag->setTagName("div");
    parentTag->setAttributeTag("id");
    parentTag->setAttributeValueTag("5");
    parentTag->setAttributeTag("class");
    parentTag->setAttributeValueTag("wrap");

    std::unique_ptr<Tag> tag(new Tag);
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("name");
    tag->setAttributeTag("id");
    tag->setAttributeValueTag("part1");
    tag->setParent(parentTag.get());
    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectChildrenTagWithAttribute, BadTag)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("div[id=\"wrap\"][class=\"part1\"]"));
    Tag* tag = nullptr;
    EXPECT_FALSE(ptr->checkRules(tag));
}

TEST(SelectChildrenTagWithAttribute, BadParent)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("div[id=\"wrap\"][class=\"part1\"]"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("part1");
    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectChildrenTagWithAttribute, BadParentName)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("div[id=\"wrap\"][class=\"part1\"]"));
    std::unique_ptr<Tag> parentTag(new Tag);
    parentTag->setTagName("body");
    parentTag->setAttributeTag("id");
    parentTag->setAttributeValueTag("wrap");

    std::unique_ptr<Tag> tag(new Tag);
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("part1");
    tag->setParent(parentTag.get());
    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectChildrenTagWithAttribute, BadParentAttribute)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("div[id=\"wrap\"][class=\"part1\"]"));
    std::unique_ptr<Tag> parentTag(new Tag);
    parentTag->setTagName("div");
    parentTag->setAttributeTag("size");
    parentTag->setAttributeValueTag("45");

    std::unique_ptr<Tag> tag(new Tag);
    tag->setAttributeTag("class");
    tag->setAttributeValueTag("part1");
    tag->setParent(parentTag.get());
    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectChildrenTagWithAttribute, BadChildAttribute)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("div[id=\"wrap\"][class=\"part1\"]"));
    std::unique_ptr<Tag> parentTag(new Tag);
    parentTag->setTagName("div");
    parentTag->setAttributeTag("id");
    parentTag->setAttributeValueTag("wrap");

    std::unique_ptr<Tag> tag(new Tag);
    tag->setAttributeTag("wdth");
    tag->setAttributeValueTag("200");
    tag->setParent(parentTag.get());
    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectChildrenTagWithAttribute, BadAllAttribute)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("div[id=\"wrap\"][class=\"part1\"]"));
    std::unique_ptr<Tag> parentTag(new Tag);
    parentTag->setTagName("div");
    parentTag->setAttributeTag("size");
    parentTag->setAttributeValueTag("10");

    std::unique_ptr<Tag> tag(new Tag);
    tag->setAttributeTag("wdth");
    tag->setAttributeValueTag("200");
    tag->setParent(parentTag.get());
    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectChildrenOfTheSpecificTag, ValidCase)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("body > div"));
    std::unique_ptr<Tag> parentTag(new Tag);
    parentTag->setTagName("body");
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setParent(parentTag.get());

    EXPECT_TRUE(ptr->checkRules(tag.get()));
}

TEST(SelectChildrenOfTheSpecificTag, ValidCase2)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("body> div"));
    std::unique_ptr<Tag> parentTag(new Tag);
    parentTag->setTagName("body");
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setParent(parentTag.get());

    EXPECT_TRUE(ptr->checkRules(tag.get()));
}

TEST(SelectChildrenOfTheSpecificTag, ValidCase3)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("body >div"));
    std::unique_ptr<Tag> parentTag(new Tag);
    parentTag->setTagName("body");
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setParent(parentTag.get());

    EXPECT_TRUE(ptr->checkRules(tag.get()));
}

TEST(SelectChildrenOfTheSpecificTag, ValidCase4)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("body>div"));
    std::unique_ptr<Tag> parentTag(new Tag);
    parentTag->setTagName("body");
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setParent(parentTag.get());

    EXPECT_TRUE(ptr->checkRules(tag.get()));
}

TEST(SelectChildrenOfTheSpecificTag, AnotherParentAndChild)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("div > body"));
    std::unique_ptr<Tag> parentTag(new Tag);
    parentTag->setTagName("body");
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setParent(parentTag.get());

    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectChildrenOfTheSpecificTag, BadRule)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("div  body"));
    EXPECT_EQ(ptr, nullptr);
}

TEST(SelectChildrenOfTheSpecificTag, BadTag)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("body>div"));
    Tag* tag = nullptr;
    EXPECT_FALSE(ptr->checkRules(tag));
}

TEST(SelectChildrenOfTheSpecificTag, BadParent)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("body > div"));
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");

    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectChildrenOfTheSpecificTag, BadParentName)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("body > div"));
    std::unique_ptr<Tag> parentTag(new Tag);
    parentTag->setTagName("html");
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("div");
    tag->setParent(parentTag.get());

    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

TEST(SelectChildrenOfTheSpecificTag, BadTagName)
{
    std::unique_ptr<CheckRulesFactory> ptr(CheckRulesFactory::createCheckRulesFactory("body > div"));
    std::unique_ptr<Tag> parentTag(new Tag);
    parentTag->setTagName("body");
    std::unique_ptr<Tag> tag(new Tag);
    tag->setTagName("p");
    tag->setParent(parentTag.get());

    EXPECT_FALSE(ptr->checkRules(tag.get()));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}