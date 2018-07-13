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

PageData ProcessPage::getData() const
{
    return m_PageData;
}

void ProcessPage::process()
{
    processHelper(m_InputPage, m_PageData);
}

PageData ProcessPage::processHelper(const std::string& input, PageData& pageData)
{
    if (!input.empty())
    {
        m_BasePtr = std::make_shared<ContentParser>(input);
        std::vector<DataParser> tempVec = m_BasePtr->parse();

        for (const auto& i : tempVec)
        {
            Teg teg;
            teg.setTegName(i.getTegName());
            teg.setContent(i.getContent());

            m_BasePtr.reset();
            m_BasePtr = std::make_shared<AttributeParser>(i.getNotParsingAttributes());

            auto attributes = m_BasePtr->parse();

            for (const auto& attributesIter : attributes)
            {
                teg.setAttributeTeg(attributesIter.getAttribute());
            }

            m_BasePtr.reset();
            m_BasePtr = std::make_shared<AttibuteValueParser>(i.getNotParsingAttributes());

            auto attributesValue = m_BasePtr->parse();

            for (const auto& attributesValueIter : attributesValue)
            {
                teg.setAttributeValueTeg(attributesValueIter.getAttributeValue());
            }

            if (!pageData.empty())
            {
                pageData.last().setChildren(&teg);
                teg.setParent(&pageData.last());
            }

            pageData.add(teg);

            processHelper(i.getContent(), pageData);
        }
    }
    return pageData;
}