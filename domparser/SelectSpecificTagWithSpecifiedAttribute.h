#ifndef DOMPARSER_SELECTSPECIFICTAGWITHSPECIFIEDATTRIBUTE_H
#define DOMPARSER_SELECTSPECIFICTAGWITHSPECIFIEDATTRIBUTE_H

#include "CheckRulesFactory.h"

class SelectSpecificTagWithSpecifiedAttribute : public CheckRulesFactory
{
public:
    explicit SelectSpecificTagWithSpecifiedAttribute(const std::cmatch&);
    virtual ~SelectSpecificTagWithSpecifiedAttribute() = default;
    virtual bool checkRules(Tag*) const;

private:
    std::vector<std::string> m_Match;
};


#endif //DOMPARSER_SELECTSPECIFICTAGWITHSPECIFIEDATTRIBUTE_H
