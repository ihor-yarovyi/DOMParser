#include "SelectChildrenTagWithAttribute.h"
#include <iterator>
#include <algorithm>

SelectChildrenTagWithAttribute::SelectChildrenTagWithAttribute(const std::cmatch& cm)
: m_Match(cm.begin(), cm.end())
{

}

bool SelectChildrenTagWithAttribute::checkRules(Tag* tag) const
{
    if (tag != nullptr && tag->getParent() != nullptr && tag->getParent()->getTagName() == m_Match[1])
    {
        auto parent = tag->getParent();
        auto parentAttributes = parent->getAttributeTag();
        auto parentAttributesValue = parent->getAttributeValueTag();
        auto parentAttributePosition = std::find(parentAttributes.begin(), parentAttributes.end(), m_Match[3]);

        if (parentAttributePosition != parentAttributes.end() &&
            parentAttributesValue[std::distance(parentAttributes.begin(), parentAttributePosition)] == m_Match[4])
        {
            auto attribute = tag->getAttributeTag();
            auto attributeValue = tag->getAttributeValueTag();
            auto attributePosition = std::find(attribute.begin(), attribute.end(), m_Match[6]);

            if (attributePosition != attribute.end() &&
                    attributeValue[std::distance(attribute.begin(), attributePosition)] == m_Match[7])
            {
                return true;
            }
        }
    }
    return false;
}