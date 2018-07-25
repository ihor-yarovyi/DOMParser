#include "PageDataFactory.h"
#include "PageDataImpl.h"

IPageData* PageDataFactory::createPageData(const std::string& path, const std::string& rule)
{
    if (!path.empty())
    {
        return new PageDataImpl(path, rule);
    }
    return nullptr;
}
