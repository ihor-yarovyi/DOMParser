#ifndef DOMPARSER_SELECTALLWITHENDSTRING_H
#define DOMPARSER_SELECTALLWITHENDSTRING_H

#include "CheckRulesFactory.h"

class SelectAllWithEndString : public CheckRulesFactory
{
public:
    SelectAllWithEndString(const std::cmatch&);
    virtual bool checkRules(Tag*) const;

private:
    std::vector<std::string> m_Match;
};


#endif //DOMPARSER_SELECTALLWITHENDSTRING_H
