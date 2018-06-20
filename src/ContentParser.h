#ifndef DOMPARSER_CONTENTPARSER_H
#define DOMPARSER_CONTENTPARSER_H

#include "BaseParser.h"
#include <regex>

class ContentParser : public BaseParser
{
public:
    ContentParser(const std::string&);
    virtual ~ContentParser() = default;

    virtual std::vector<std::string> parse();

private:
    std::regex m_RegexValue;
};

#endif //DOMPARSER_CONTENTPARSER_H
