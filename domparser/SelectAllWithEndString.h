#ifndef DOMPARSER_SELECTALLWITHENDSTRING_H
#define DOMPARSER_SELECTALLWITHENDSTRING_H

#include "CheckRulesFactory.h"

class SelectAllWithEndString : public CheckRulesFactory
{
public:
    explicit SelectAllWithEndString(const std::cmatch&);
    virtual ~SelectAllWithEndString() = default;
    virtual bool checkRules(Tag*) const;

private:
    std::vector<std::string> m_Match;
};


#endif //DOMPARSER_SELECTALLWITHENDSTRING_H
