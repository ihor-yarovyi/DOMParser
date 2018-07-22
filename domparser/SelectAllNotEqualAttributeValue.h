#ifndef DOMPARSER_SELECTALLNOTEQUALATTRIBUTEVALUE_H
#define DOMPARSER_SELECTALLNOTEQUALATTRIBUTEVALUE_H

#include "CheckRulesFactory.h"

class SelectAllNotEqualAttributeValue : public CheckRulesFactory
{
public:
    explicit SelectAllNotEqualAttributeValue(const std::cmatch&);
    virtual bool checkRules(Tag*) const;

private:
    std::vector<std::string> m_Match;
};


#endif //DOMPARSER_SELECTALLNOTEQUALATTRIBUTEVALUE_H
