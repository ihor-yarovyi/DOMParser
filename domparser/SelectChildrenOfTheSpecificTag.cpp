#include "SelectChildrenOfTheSpecificTag.h"

SelectChildrenOfTheSpecificTag::SelectChildrenOfTheSpecificTag(const std::cmatch& cm)
: m_Match(cm.begin(), cm.end())
{

}

bool SelectChildrenOfTheSpecificTag::checkRules(Tag* tag) const
{
    if (tag != nullptr)
    {
        return tag->getParent() != nullptr && tag->getParent()->getTagName() == m_Match[1] && tag->getTagName() == m_Match[2];
    }
    return false;
}