#ifndef DOMPARSER_CHECKRULESFACTORY_H
#define DOMPARSER_CHECKRULESFACTORY_H

#include "Tag.h"
#include <vector>
#include <string>
#include <regex>

class CheckRulesFactory
{
public:
    CheckRulesFactory() = default;
    virtual ~CheckRulesFactory() = default;
    virtual bool checkRules(Tag*) const = 0;
    static CheckRulesFactory* createCheckRulesFactory(const std::string&);
};

#endif //DOMPARSER_CHECKRULESFACTORY_H
