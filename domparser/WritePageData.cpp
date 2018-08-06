#include "WritePageData.h"
#include <stdexcept>

WritePageData::WritePageData(std::shared_ptr<IPageData> ptr, const std::string& fileName)
: m_PageData(ptr),
  m_FileOutput(fileName, std::ios::out)
{

}

void WritePageData::setPageData(std::shared_ptr<IPageData> ptr)
{
    if (m_PageData != nullptr)
    {
        m_PageData.reset();
    }
    m_PageData = ptr;
}

void WritePageData::writeToFile()
{
    if (m_PageData == nullptr)
    {
        throw std::logic_error("Page data is null");
    }
    writeToFileHelper(m_PageData);
    m_FileOutput.close();
}

void WritePageData::writeToFileHelper(std::shared_ptr<IPageData> pageData)
{
    if (pageData->current() != nullptr)
    {
        auto currentTag = pageData->current();
        std::string output("<" + currentTag->getTagName());
        auto attributes = currentTag->getAttributeTag();

        if (!attributes.empty())
        {
            auto attributesValue = currentTag->getAttributeValueTag();

            for (size_t i = 0; i < attributes.size() && i < attributesValue.size(); ++i)
            {
                std::string argument(" " + attributes[i] + "=\"" + attributesValue[i] + "\"");
                output += argument;
            }
        }
        output += ">\n";
        m_FileOutput << output;

        auto children = currentTag->getChildren();

        if (!children.empty())
        {
            for (const auto& i : children)
            {
                m_PageData->next();
                writeToFileHelper(m_PageData);
            }
        }
        else
        {
            m_FileOutput << currentTag->getContent() << "\n";
        }
        m_FileOutput << "</" << currentTag->getTagName() << ">\n";
    }
}