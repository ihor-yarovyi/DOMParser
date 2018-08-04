#ifndef DOMPARSER_SELECTCHILDRENOFTHESPECIFICTAG_H
#define DOMPARSER_SELECTCHILDRENOFTHESPECIFICTAG_H

#include "CheckRulesFactory.h"

class SelectChildrenOfTheSpecificTag : public CheckRulesFactory
{
public:
    explicit SelectChildrenOfTheSpecificTag(const std::cmatch&);
    virtual ~SelectChildrenOfTheSpecificTag() = default;
    virtual bool checkRules(Tag*) const;

private:
    std::vector<std::string> m_Match;
};

#endif //DOMPARSER_SELECTCHILDRENOFTHESPECIFICTAG_H
