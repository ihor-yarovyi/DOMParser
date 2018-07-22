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
                    auto attributeValuePosition = std::find_if(attributeValue.begin(), attributeValue.end(),
                            [&sm](const std::string& str)
                            {
                                std::cmatch loc;
                                return std::regex_search(str.data(), loc, std::regex("(" + sm[3].str() + ")"));
                            });

                    if (attributePosition == attribute.end() || attributeValuePosition == attributeValue.end())
                    {
                        return false;
                    }
                    ++next;
                }
                return true;
            }
            catch (const std::regex_error& e)
            {
                // TODO: Make handler of the exception
            }
        }
    }
    return false;
}