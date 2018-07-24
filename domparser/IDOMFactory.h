#ifndef DOMPARSER_IDOMFACTORY_H
#define DOMPARSER_IDOMFACTORY_H

#include "IPageData.h"
#include <string>

class IDOMFactory
{
public:
    IDOMFactory() = default;
    ~IDOMFactory() = default;
    virtual IPageData* createPageData(const std::string&, const std::string& = "*") = 0;
};

#endif //DOMPARSER_IDOMFACTORY_H
