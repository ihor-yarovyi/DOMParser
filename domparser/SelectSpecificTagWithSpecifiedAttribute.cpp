#include "SelectSpecificTagWithSpecifiedAttribute.h"
#include <algorithm>
#include <iterator>

SelectSpecificTagWithSpecifiedAttribute::SelectSpecificTagWithSpecifiedAttribute(const std::cmatch& cm)
: m_Match(cm.begin(), cm.end())
{

}

bool SelectSpecificTagWithSpecifiedAttribute::checkRules(Tag* tag) const
{
    if (tag != nullptr && tag->getTagName() == m_Match[2])
    {
        auto attribute = tag->getAttributeTag();
        auto attributeValue = tag->getAttributeValueTag();
        auto attributePosition = std::find(attribute.begin(), attribute.end(), m_Match[3]);

        if (attributePosition != attribute.end() &&
            attributeValue[std::distance(attribute.begin(), attributePosition)] == m_Match[4])
        {
            return true;
        }
    }
    return false;
}