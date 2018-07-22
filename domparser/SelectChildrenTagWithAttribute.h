#ifndef DOMPARSER_SELECTCHILDRENTAGWITHATTRIBUTE_H
#define DOMPARSER_SELECTCHILDRENTAGWITHATTRIBUTE_H

#include "CheckRulesFactory.h"

class SelectChildrenTagWithAttribute : public CheckRulesFactory
{
public:
    explicit SelectChildrenTagWithAttribute(const std::cmatch&);
    virtual bool checkRules(Tag*) const;

private:
    std::vector<std::string> m_Match;
};

#endif //DOMPARSER_SELECTCHILDRENTAGWITHATTRIBUTE_H
