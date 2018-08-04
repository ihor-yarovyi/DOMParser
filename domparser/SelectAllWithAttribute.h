#ifndef DOMPARSER_SELECTALLWITHATTRIBUTE_H
#define DOMPARSER_SELECTALLWITHATTRIBUTE_H

#include "CheckRulesFactory.h"

class SelectAllWithAttribute : public CheckRulesFactory
{
public:
    explicit SelectAllWithAttribute(const std::cmatch&);
    virtual ~SelectAllWithAttribute() = default;
    virtual bool checkRules(Tag*) const;

private:
    std::vector<std::string> m_Match;
};


#endif //DOMPARSER_SELECTALLWITHATTRIBUTE_H
