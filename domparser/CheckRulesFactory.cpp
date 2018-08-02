#include "CheckRulesFactory.h"
#include "SelectAllRule.h"
#include "SelectDivRule.h"
#include "SelectAllWithAttribute.h"
#include "SelectAllWithAttributeAndValue.h"
#include "SelectAllWithEndString.h"
#include "SelectAllNotEqualAttributeValue.h"
#include "SelectAllWithBeginString.h"
#include "SelectAllWithPartString.h"
#include "SelectTagsWithMatchingAttributes.h"
#include "SelectSpecificTagWithSpecifiedAttribute.h"
#include "SelectChildrenTagWithAttribute.h"
#include "SelectChildrenOfTheSpecificTag.h"

CheckRulesFactory* CheckRulesFactory::createCheckRulesFactory(const std::string& rule)
{
    std::vector<std::string> regexValue;
    regexValue.emplace_back("^\\*{1}");
    regexValue.emplace_back("^(div)$");
    regexValue.emplace_back(R"((\[([\w]+)\]))");
    regexValue.emplace_back(R"((\[([\w]+)=\'([\w]+)\'\]))");
    regexValue.emplace_back(R"((\[([\w]+)\$\=\'(\.[\w]+)\'\]))");
    regexValue.emplace_back(R"((\[([\w]+)\!\=\'([\w\.+]+)\'\]))");
    regexValue.emplace_back(R"((\[([\w]+)\^\=\'([\w.]+)\'\]))");
    regexValue.emplace_back(R"((\[([\w]+)\*\=\'([\w.]+)\'\]))");
    regexValue.emplace_back(R"(^(\[([\w]+)\=\"([\w.]+)\"\]))");
    regexValue.emplace_back(R"((^(\w+)\[([\w]+)\=\"([\w.]+)\"\])$)");
    regexValue.emplace_back(R"(^(\w+)(\[([\w]+)\=\"([\w.]+)\"\])(\[([\w]+)\=\"([\w.]+)\"\])$)");
    regexValue.emplace_back(R"(^(\w+)\s*\>\s*(\w+)$)");

    std::cmatch cm;

    for (size_t i = 0; i < regexValue.size(); ++i)
    {
        if (std::regex_search(rule.data(), cm, std::regex(regexValue[i])))
        {
            switch (i)
            {
                case 0: return new SelectAllRule();
                case 1: return new SelectDivRule(cm);
                case 2: return new SelectAllWithAttribute(cm);
                case 3: return new SelectAllWithAttributeAndValue(cm);
                case 4: return new SelectAllWithEndString(cm);
                case 5: return new SelectAllNotEqualAttributeValue(cm);
                case 6: return new SelectAllWithBeginString(cm);
                case 7: return new SelectAllWithPartString(cm);
                case 8: return new SelectTagsWithMatchingAttributes(rule, regexValue[i].substr(1, regexValue[i].size()));
                case 9: return new SelectSpecificTagWithSpecifiedAttribute(cm);
                case 10: return new SelectChildrenTagWithAttribute(cm);
                case 11: return new SelectChildrenOfTheSpecificTag(cm);
            }
        }
    }
    return nullptr;
}

