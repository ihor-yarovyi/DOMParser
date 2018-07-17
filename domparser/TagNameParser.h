#ifndef DOMPARSER_TEGNAMEPARSER_H
#define DOMPARSER_TEGNAMEPARSER_H

#include "BaseParser.h"
#include <regex>

class TagNameParser : public BaseParser
{
public:
    TagNameParser(const std::string&);
    virtual ~TagNameParser() = default;

    virtual std::vector<DataParser> parse();

private:
    std::regex m_RegexValue;
};


#endif //DOMPARSER_TEGNAMEPARSER_H
