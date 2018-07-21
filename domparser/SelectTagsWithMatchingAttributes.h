#ifndef DOMPARSER_SELECTTAGSWITHMATCHINGATTRIBUTES_H
#define DOMPARSER_SELECTTAGSWITHMATCHINGATTRIBUTES_H

#include "CheckRulesFactory.h"

class SelectTagsWithMatchingAttributes : public CheckRulesFactory
{
public:
    SelectTagsWithMatchingAttributes(const std::string&, const std::string&);
    virtual bool checkRules(Tag*) const;

private:
    std::string m_FullRule;
    std::regex m_RegexValue;
};


#endif //DOMPARSER_SELECTTAGSWITHMATCHINGATTRIBUTES_H
