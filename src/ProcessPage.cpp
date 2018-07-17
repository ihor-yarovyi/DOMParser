#include "ProcessPage.h"
#include "ContentParser.h"
#include "AttributeParser.h"
#include "AttributeValueParser.h"
#include "TegNameParser.h"

#include <fstream>

ProcessPage::ProcessPage(const std::string& pathToPage)
: m_BasePtr(nullptr)
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

std::vector<Teg> ProcessPage::getPageData() const
{
    return m_PageData;
}

void ProcessPage::process()
{
    processHelper(m_InputPage, m_PageData, nullptr);
}

std::vector<Teg> ProcessPage::processHelper(const std::string& input, std::vector<Teg>& pageData, Teg* tegPtr)
{
    if (!input.empty())
    {
        std::unique_ptr<BaseParser> basePtr(new ContentParser(input));
        std::vector<DataParser> tempVec = basePtr->parse();

        for (const auto& i : tempVec)
        {
            Teg* teg = new Teg;
            teg->setTegName(i.getTegName());
            teg->setContent(i.getContent());
            basePtr.reset();
            basePtr = std::make_unique<AttributeParser>(i.getNotParsingAttributes());
            auto attributes = basePtr->parse();

            for (const auto& attributesIter : attributes)
            {
                teg->setAttributeTeg(attributesIter.getAttribute());
            }

            basePtr.reset();
            basePtr = std::make_unique<AttibuteValueParser>(i.getNotParsingAttributes());
            auto attributesValue = basePtr->parse();

            for (const auto& attributesValueIter : attributesValue)
            {
                teg->setAttributeValueTeg(attributesValueIter.getAttributeValue());
            }

            teg->setParent(tegPtr);
            
            if (tegPtr != nullptr)
            {
                auto position = std::find(pageData.begin(), pageData.end(), tegPtr);
                position->setChildren(teg);
            }

            pageData.emplace_back(*teg);
            processHelper(i.getContent(), pageData, teg);
        }
    }
    return pageData;
}