#ifndef DOMPARSER_TEGNAMEPARSER_H
#define DOMPARSER_TEGNAMEPARSER_H

#include "BaseParser.h"
#include <regex>

class TegNameParser : public BaseParser
{
public:
    TegNameParser(const std::string&);
    virtual ~TegNameParser() = default;

    virtual std::vector<DataParser> parse();

private:
    std::regex m_RegexValue;
};


#endif //DOMPARSER_TEGNAMEPARSER_H
