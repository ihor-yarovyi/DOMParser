#include "PageDataImpl.h"

PageDataImpl::PageDataImpl(const std::string& path, const std::string& rules)
{
    m_ProcessPage.setWebPage(path);
    m_ProcessPage.setRules(rules);
    m_ProcessPage.process();
    m_Data = m_ProcessPage.getPageData();
}

PageDataImpl::~PageDataImpl()
{

}

std::vector<Tag> PageDataImpl::getPageData(const std::string& rules) const
{
    // TODO: add rules parameters in the ProcessPage
    //return m_ProcessPage.getPageData();
    // Maybe
    return m_Data;
}

Tag* PageDataImpl::first()
{
    if (!m_Data.empty())
    {
        return &m_Data.front();
    }
    return nullptr;
}

Tag* PageDataImpl::last()
{
    if (!m_Data.empty())
    {
        return &m_Data.back();
    }
    return nullptr;
}

Tag* PageDataImpl::parent(Tag* tag)
{
    return tag->getParent();
}


