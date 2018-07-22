#ifndef DOMPARSER_SELECTALLWITHATTRIBUTEANDVALUE_H
#define DOMPARSER_SELECTALLWITHATTRIBUTEANDVALUE_H

#include "CheckRulesFactory.h"

class SelectAllWithAttributeAndValue : public CheckRulesFactory
{
public:
    explicit SelectAllWithAttributeAndValue(const std::cmatch&);
    virtual bool checkRules(Tag*) const;

private:
    std::vector<std::string> m_Match;
};


#endif //DOMPARSER_SELECTALLWITHATTRIBUTEANDVALUE_H
