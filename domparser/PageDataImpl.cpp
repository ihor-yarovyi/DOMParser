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
    auto position = std::find_if(m_Data.begin(), m_Data.end(),
                                 [&parent](const Tag& tag)
                                 {
                                     return tag.getTagName() == parent->getTagName() &&
                                            tag.getParent() == parent->getParent() &&
                                            tag.getAttributeTag() == parent->getAttributeTag() &&
                                            tag.getAttributeValueTag() == parent->getAttributeValueTag() &&
                                            tag.getContent() == parent->getContent();
                                 });

    if (parent != nullptr)
    {
        std::vector<Tag*> children = position->getChildren();
        for (const auto& i : children)
        {
            if (!compareTags(m_Data[m_CurrentTag], i))
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

bool PageDataImpl::changeAttribute(const std::string& attributeOldName, const std::string& attributeOldValue, const std::string& attributeNewName, const std::string& attributeNewValue)
{
    if (!m_Data.empty())
    {
        auto attributes = &m_Data[m_CurrentTag].getAttributeTag();
        auto attributePosition = std::find(attributes->begin(), attributes->end(), attributeOldName);
        if (attributePosition != attributes->end())
        {
            auto attributeValue = &m_Data[m_CurrentTag].getAttributeValueTag();
            auto attributeValuePosition = std::find(attributeValue->begin(), attributeValue->end(), attributeOldValue);

            if (attributeValuePosition != attributeValue->end() &&
                std::distance(attributes->begin(), attributePosition) == std::distance(attributeValue->begin(), attributeValuePosition))
            {
                *attributePosition = attributeNewName;
                *attributeValuePosition = attributeNewValue;
                return true;
            }
        }
    }
    return false;
}

bool PageDataImpl::removeAttribute(const std::string& attributeName, const std::string& attributeValue)
{
    if (!m_Data.empty())
    {
        auto attributesPtr = &m_Data[m_CurrentTag].getAttributeTag();
        auto attributesValuePtr = &m_Data[m_CurrentTag].getAttributeValueTag();
        auto attributePosition = std::find(attributesPtr->begin(), attributesPtr->end(), attributeName);
        auto attributeValuePosition = std::find(attributesValuePtr->begin(), attributesValuePtr->end(), attributeValue);

        if (attributePosition != attributesPtr->end() && attributeValuePosition != attributesValuePtr->end()
            && std::distance(attributesPtr->begin(), attributePosition) == std::distance(attributesValuePtr->begin(), attributeValuePosition))
        {
            auto attributeNextPosition = attributePosition;
            ++attributeNextPosition;
            auto attributeValueNextPosition = attributeValuePosition;
            ++attributeValueNextPosition;

            while (attributeNextPosition != attributesPtr->end() && attributeValueNextPosition != attributesValuePtr->end())
            {
                *attributePosition++ = *attributeNextPosition++;
                *attributeValuePosition++ = *attributeValueNextPosition++;
            }
            attributesPtr->erase(attributePosition, attributesPtr->end());
            attributesValuePtr->erase(attributeValuePosition, attributesValuePtr->end());
            return true;
        }
    }
    return false;
}

void PageDataImpl::pushBack(const Tag& tag)
{
    m_Data.emplace_back(tag);
}

void PageDataImpl::pushFront(const Tag& tag)
{
    std::vector<Tag> temp;
    temp.reserve(m_Data.size() + 1);
    temp.emplace_back(tag);
    for (const auto& i : m_Data)
    {
        temp.emplace_back(i);
    }
    m_Data = std::move(temp);
}

bool PageDataImpl::pushBefore(const Tag& existTag, const Tag& newTag)
{
    auto position = std::find(m_Data.begin(), m_Data.end(), existTag);
    if (position != m_Data.end())
    {
        m_Data.insert(position, newTag);
        return true;
    }
    return false;
}

bool PageDataImpl::pushBefore(size_t index, const Tag& newTag)
{
    if (index < m_Data.size())
    {
        auto position = m_Data.begin() + index;
        m_Data.insert(position, newTag);
        return true;
    }
    return false;
}