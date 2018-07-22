#include "SelectAllWithEndString.h"
#include <algorithm>
#include <iterator>

SelectAllWithEndString::SelectAllWithEndString(const std::cmatch& cm)
: m_Match(cm.begin(), cm.end())
{

}

bool SelectAllWithEndString::checkRules(Tag* tag) const
{
    if (tag != nullptr)
    {
        auto attribute = tag->getAttributeTag();
        auto attributeValue = tag->getAttributeValueTag();
        auto attributePosition = std::find(attribute.begin(), attribute.end(), m_Match[2]);
        std::cmatch cm;

        if (attributePosition != attribute.end() &&
                std::regex_search(attributeValue[std::distance(attribute.begin(), attributePosition)].data(), cm, std::regex("(" + m_Match[3] + ")$")))
        {
            return true;
        }
    }
    return false;
}