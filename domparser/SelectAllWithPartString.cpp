#include "SelectAllWithPartString.h"

SelectAllWithPartString::SelectAllWithPartString(const std::cmatch& cm)
: m_Match(cm.begin(), cm.end())
{

}

bool SelectAllWithPartString::checkRules(Tag* tag) const
{
    if (tag != nullptr)
    {
        auto attribute = tag->getAttributeTag();
        auto attributeValue = tag->getAttributeValueTag();

        if (attribute.size() == attributeValue.size())
        {
            std::cmatch cm;
            for (size_t i = 0; i < attribute.size(); ++i)
            {
                if (attribute[i] == m_Match[2] && std::regex_search(attributeValue[i].data(), cm, std::regex("(" + m_Match[3] + ")")))
                {
                    return true;
                }
            }
        }
    }
    return false;
}