#include "SelectTagsWithMatchingAttributes.h"
#include <functional>
#include <algorithm>

SelectTagsWithMatchingAttributes::SelectTagsWithMatchingAttributes(const std::string& rule, const std::string& reg)
: m_FullRule(rule),
  m_RegexValue(reg)
{

}

bool SelectTagsWithMatchingAttributes::checkRules(Tag* tag) const
{
    if (tag != nullptr)
    {
        auto attribute = tag->getAttributeTag();
        auto attributeValue = tag->getAttributeValueTag();

        if (attribute.size() == attributeValue.size())
        {
            try
            {
                std::sregex_iterator next(m_FullRule.begin(), m_FullRule.end(), m_RegexValue);
                std::sregex_iterator end;
                std::smatch sm;

                while (next != end)
                {
                    sm = *next;
                    auto attributePosition = std::find(attribute.begin(), attribute.end(), sm[2].str());
                    std::cmatch loc;
                    if (attributePosition == attribute.end() ||
                        !std::regex_search(attributeValue[std::distance(attribute.begin(), attributePosition)].data(), loc, std::regex("(" + sm[3].str() + ")")))
                    {
                        return false;
                    }
                    ++next;
                }
                return true;
            }
            catch (const std::regex_error&)
            {
                throw;
            }
        }
    }
    return false;
}