#include "SelectAllWithAttribute.h"

SelectAllWithAttribute::SelectAllWithAttribute(const std::cmatch& cm)
: m_Match(cm.begin(), cm.end())
{

}

bool SelectAllWithAttribute::checkRules(Tag* tag) const
{
    if (tag != nullptr)
    {
        for (const auto &i : tag->getAttributeTag())
        {
            if (m_Match[2] == i)
            {
                return true;
            }
        }
    }
    return false;
}