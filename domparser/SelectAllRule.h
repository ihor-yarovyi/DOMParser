#ifndef DOMPARSER_SELECTALLRULE_H
#define DOMPARSER_SELECTALLRULE_H

#include <regex>

#include "CheckRulesFactory.h"

class SelectAllRule : public CheckRulesFactory
{
public:
    SelectAllRule() = default;
    virtual bool checkRules(Tag*) const;
};


#endif //DOMPARSER_SELECTALLRULE_H
