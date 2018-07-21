#ifndef DOMPARSER_SELECTALLWITHPARTSTRING_H
#define DOMPARSER_SELECTALLWITHPARTSTRING_H

#include "CheckRulesFactory.h"

class SelectAllWithPartString : public CheckRulesFactory
{
public:
    SelectAllWithPartString(const std::cmatch&);
    virtual bool checkRules(Tag*) const;

private:
    std::vector<std::string> m_Match;
};


#endif //DOMPARSER_SELECTALLWITHPARTSTRING_H
