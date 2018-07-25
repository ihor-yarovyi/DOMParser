#ifndef DOMPARSER_PAGEDATAFACTORYIMPL_H
#define DOMPARSER_PAGEDATAFACTORYIMPL_H

#include "IDOMFactory.h"

class PageDataFactory : public IDOMFactory
{
public:
    virtual IPageData* createPageData(const std::string&, const std::string& = "*");
};


#endif //DOMPARSER_PAGEDATAFACTORYIMPL_H
