#include "ProcessPage.h"
#include "ContentParser.h"
#include "AttributeParser.h"
#include "AttributeValueParser.h"
#include "TagNameParser.h"

#include <fstream>

ProcessPage::ProcessPage(const std::string& pathToPage)
{
    processInputPageHelper(pathToPage);
}

void ProcessPage::setWebPage(const std::string& pathToPage)
{
    processInputPageHelper(pathToPage);
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
    processHelper(m_InputPage, m_PageData, nullptr);
}

std::vector<Tag> ProcessPage::processHelper(const std::string& input, std::vector<Tag>& pageData, Tag* tagPtr)
{
    if (!input.empty())
    {
        std::unique_ptr<BaseParser> basePtr(new ContentParser(input));
        std::vector<DataParser> tempVec = basePtr->parse();

        for (const auto& i : tempVec)
        {
            Tag* tag = new Tag;
            tag->setTagName(i.getTagName());
            tag->setContent(i.getContent());
            basePtr.reset();
            basePtr = std::make_unique<AttributeParser>(i.getNotParsingAttributes());
            auto attributes = basePtr->parse();

            for (const auto& attributesIter : attributes)
            {
                tag->setAttributeTag(attributesIter.getAttribute());
            }

            basePtr.reset();
            basePtr = std::make_unique<AttibuteValueParser>(i.getNotParsingAttributes());
            auto attributesValue = basePtr->parse();

            for (const auto& attributesValueIter : attributesValue)
            {
                tag->setAttributeValueTag(attributesValueIter.getAttributeValue());
            }

            tag->setParent(tagPtr);
            
            if (tagPtr != nullptr)
            {
                auto position = std::find(pageData.begin(), pageData.end(), tagPtr);
                position->setChildren(tag);
            }

            pageData.emplace_back(*tag);
            processHelper(i.getContent(), pageData, tag);
        }
    }
    return pageData;
}