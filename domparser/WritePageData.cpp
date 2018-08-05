#include "WritePageData.h"

WritePageData::WritePageData(std::unique_ptr<IPageData> ptr)
{
    m_PageData = std::move(ptr);
}

void WritePageData::setPageData(std::unique_ptr<IPageData> ptr)
{
    if (m_PageData != nullptr)
    {
        m_PageData.reset();
    }
    m_PageData = std::move(ptr);
}

