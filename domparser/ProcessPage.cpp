#include "ProcessPage.h"
#include "ContentParser.h"
#include "AttributeParser.h"
#include "AttributeValueParser.h"
#include "TagNameParser.h"

#include <fstream>
#include <stdexcept>

ProcessPage::ProcessPage(const std::string& pathToPage, const std::string& rule)
: m_CheckRulePtr(CheckRulesFactory::createCheckRulesFactory(rule))
{
    processInputPageHelper(pathToPage);
}

void ProcessPage::setWebPage(const std::string& pathToPage)
{
    processInputPageHelper(pathToPage);
}

void ProcessPage::setSourceWebPage(const std::string& dataPage)
{
    m_InputPage = dataPage;
}

void ProcessPage::processInputPageHelper(const std::string& pathToPage)
{
    std::ifstream inputFile(pathToPage, std::ios::in);
    m_InputPage.insert(m_InputPage.begin(), std::istreambuf_iterator<char>(inputFile), std::istreambuf_iterator<char>());
}

std::vector<Tag> ProcessPage::getPageData() const
{
    return m_PageData;
}

void ProcessPage::process()
{
    if (m_CheckRulePtr == nullptr)
    {
        throw std::logic_error("Rule is incorrect");
    }
    processHelper(m_InputPage, m_PageData, nullptr);
}

void ProcessPage::processHelper(const std::string& input, std::vector<Tag>& pageData, Tag* tagPtr)
{
    if (!input.empty())
    {
        auto tempVec = ContentParser(input).parse();

        for (const auto& i : tempVec)
        {
            Tag* tag = new Tag;
            tag->setTagName(i.getTagName());
            tag->setContent(i.getContent());
            auto attributes = AttributeParser(i.getNotParsingAttributes()).parse();

            for (const auto& attributesIter : attributes)
            {
                tag->setAttributeTag(attributesIter.getAttribute());
            }
            auto attributesValue = AttibuteValueParser(i.getNotParsingAttributes()).parse();

            for (const auto& attributesValueIter : attributesValue)
            {
                tag->setAttributeValueTag(attributesValueIter.getAttributeValue());
            }

            tag->setParent(tagPtr);
            
            if (tagPtr != nullptr && !pageData.empty())
            {
                auto position = std::find(pageData.begin(), pageData.end(), tagPtr);
                if (position != pageData.end())
                {
                    position->setChildren(tag);
                }
            }

            if (m_CheckRulePtr->checkRules(tag))
            {
                pageData.emplace_back(*tag);
            }
            processHelper(i.getContent(), pageData, tag);
        }
    }
}