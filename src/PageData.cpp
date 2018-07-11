#include "PageData.h"

void PageData::add(const Teg& teg)
{
    m_Page.emplace_back(teg);
}

std::vector<Teg> PageData::getData() const
{
    return m_Page;
}

bool PageData::empty() const
{
    return m_Page.empty();
}

Teg& PageData::first()
{
    return m_Page.front();
}

Teg& PageData::last()
{
    return m_Page.back();
}
