#ifndef DOMPARSER_SELECTALLWITHATTRIBUTE_H
#define DOMPARSER_SELECTALLWITHATTRIBUTE_H

#include "CheckRulesFactory.h"

class SelectAllWithAttribute : public CheckRulesFactory
{
public:
    SelectAllWithAttribute(const std::cmatch&);
    virtual bool checkRules(Tag* tag) const;

private:
    std::vector<std::string> m_Match;
};


#endif //DOMPARSER_SELECTALLWITHATTRIBUTE_H
