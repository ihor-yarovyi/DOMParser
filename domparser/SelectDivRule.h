#ifndef DOMPARSER_SELECTDIVRULE_H
#define DOMPARSER_SELECTDIVRULE_H

#include "CheckRulesFactory.h"

class SelectDivRule : public CheckRulesFactory
{
public:
    SelectDivRule(const std::cmatch&);
    virtual bool checkRules(Tag*) const;

private:
    std::cmatch m_Match;
};


#endif //DOMPARSER_SELECTDIVRULE_H
