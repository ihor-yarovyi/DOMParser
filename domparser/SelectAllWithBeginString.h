#ifndef DOMPARSER_SELECTALLWITHBEGINSTRING_H
#define DOMPARSER_SELECTALLWITHBEGINSTRING_H

#include "CheckRulesFactory.h"

class SelectAllWithBeginString : public CheckRulesFactory
{
public:
    explicit SelectAllWithBeginString(const std::cmatch&);
    virtual bool checkRules(Tag*) const;

private:
    std::vector<std::string> m_Match;
};

#endif //DOMPARSER_SELECTALLWITHBEGINSTRING_H
