#ifndef DOMPARSER_ATTIBUTEVALUEPARSER_H
#define DOMPARSER_ATTIBUTEVALUEPARSER_H

#include "BaseParser.h"
#include <regex>

class AttibuteValueParser : public BaseParser
{
public:
    AttibuteValueParser(const std::string&);
    virtual ~AttibuteValueParser() = default;

    virtual std::vector<std::string> parse();

private:
    std::regex m_RegexValue;
};


#endif //DOMPARSER_ATTIBUTEVALUEPARSER_H
