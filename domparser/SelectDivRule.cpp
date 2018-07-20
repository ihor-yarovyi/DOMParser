#include "SelectDivRule.h"

SelectDivRule::SelectDivRule(const std::cmatch& cm)
: m_Match(cm)
{

}

bool SelectDivRule::checkRules(Tag* tag) const
{
    if (tag != nullptr && m_Match.str() == tag->getTagName())
    {
        return true;
    }
    return false;
}