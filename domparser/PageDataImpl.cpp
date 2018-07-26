#include "PageDataImpl.h"
#include <functional>
#include <iterator>

PageDataImpl::PageDataImpl(const std::string& path, const std::string& rules)
: m_ProcessPage(path, rules)
{
    m_ProcessPage.process();
    m_Data = std::move(m_ProcessPage.getPageData());
}

size_t PageDataImpl::getNumberOfTags() const
{
    return m_Data.size();
}

bool PageDataImpl::setCurrentTag(size_t index)
{
    if (index < m_Data.size())
    {
        m_CurrentTag = index;
        return true;
    }
    return false;
}

bool PageDataImpl::compareTags(const Tag& lTag, Tag* rTag) const
{
    return lTag.getTagName() == rTag->getTagName() &&
           lTag.getParent() == rTag->getParent() &&
           lTag.getAttributeTag() == rTag->getAttributeTag() &&
           lTag.getAttributeValueTag() == rTag->getAttributeValueTag() &&
           lTag.getContent() == rTag->getContent();
}

Tag* PageDataImpl::first()
{
    if (!m_Data.empty())
    {
        return &m_Data.front();
    }
    return nullptr;
}

Tag* PageDataImpl::last()
{
    if (!m_Data.empty())
    {
        return &m_Data.back();
    }
    return nullptr;
}

Tag* PageDataImpl::next()
{
    if (m_CurrentTag + 1 < m_Data.size())
    {
        return &m_Data[++m_CurrentTag];
    }
    return nullptr;
}

Tag* PageDataImpl::prev()
{
    if (m_CurrentTag - 1 >= 0)
    {
        return &m_Data[--m_CurrentTag];
    }
    return nullptr;
}

Tag* PageDataImpl::parent() const
{
    if (!m_Data.empty())
    {
        return m_Data[m_CurrentTag].getParent();
    }
    return nullptr;
}

Tag* PageDataImpl::current()
{
    if (!m_Data.empty())
    {
        return &m_Data[m_CurrentTag];
    }
    return nullptr;
}

std::vector<Tag*> PageDataImpl::children() const
{
    if (!m_Data.empty())
    {
        return m_Data[m_CurrentTag].getChildren();
    }
    return {};
}

std::vector<Tag*> PageDataImpl::siblings() const
{
    std::vector<Tag*> result {};
    auto parent = m_Data[m_CurrentTag].getParent();

    if (!m_Data.empty() && parent != nullptr)
    {
        auto children = parent->getChildren();
        for (const auto& i : children)
        {
            if (i != &m_Data[m_CurrentTag])
            {
                result.emplace_back(i);
            }
        }
    }
    return result;
}

bool PageDataImpl::insertAttribute(const std::string& attributeName, const std::string& attributeValue)
{
    if (!m_Data.empty())
    {
        m_Data[m_CurrentTag].setAttributeTag(attributeName);
        m_Data[m_CurrentTag].setAttributeValueTag(attributeValue);
        return true;
    }
    return false;
}

bool PageDataImpl::changeAttribute(const std::string& attributeName, const std::string& attributeNewName, const std::string& attributeNewValue)
{
    if (!m_Data.empty())
    {
        auto attributes = m_Data[m_CurrentTag].getAttributeTag();
        auto attributePosition = std::find(attributes.begin(), attributes.end(), attributeName);
        if (attributePosition != attributes.end())
        {
            auto attributesValue = m_Data[m_CurrentTag].getAttributeValueTag();
            *attributePosition = attributeNewName;
            attributesValue[std::distance(attributes.begin(), attributePosition)] = attributeNewValue;
            return true;
        }
    }
    return false;
}


