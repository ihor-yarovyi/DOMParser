#ifndef DOMPARSER_ATTIBUTEVALUEPARSER_H
#define DOMPARSER_ATTIBUTEVALUEPARSER_H

#include "BaseParser.h"
#include <regex>

class AttibuteValueParser : public BaseParser
{
public:
    explicit AttibuteValueParser(const std::string&);
    virtual ~AttibuteValueParser() = default;
    virtual std::vector<DataParser> parse();

private:
    std::regex m_RegexValue;
};

#endif //DOMPARSER_ATTIBUTEVALUEPARSER_H
