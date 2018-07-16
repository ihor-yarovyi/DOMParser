#include "PageData.h"

void PageData::add(const Tag& teg)
{
    m_Page.emplace_back(teg);
}

std::vector<Tag> PageData::getData() const
{
    return m_Page;
}

bool PageData::empty() const
{
    return m_Page.empty();
}

Tag& PageData::first()
{
    return m_Page.front();
}

Tag& PageData::last()
{
    return m_Page.back();
}
