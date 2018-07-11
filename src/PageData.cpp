#include "PageData.h"

void PageData::add(const Teg& teg)
{
    m_Page.emplace_back(teg);
}
