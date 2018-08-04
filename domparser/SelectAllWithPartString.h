#ifndef DOMPARSER_SELECTALLWITHPARTSTRING_H
#define DOMPARSER_SELECTALLWITHPARTSTRING_H

#include "CheckRulesFactory.h"

class SelectAllWithPartString : public CheckRulesFactory
{
public:
    explicit SelectAllWithPartString(const std::cmatch&);
    virtual ~SelectAllWithPartString() = default;
    virtual bool checkRules(Tag*) const;

private:
    std::vector<std::string> m_Match;
};


#endif //DOMPARSER_SELECTALLWITHPARTSTRING_H
