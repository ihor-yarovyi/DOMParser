#ifndef DOMPARSER_ATTRIBUTEPARSER_H
#define DOMPARSER_ATTRIBUTEPARSER_H

#include "BaseParser.h"
#include <regex>

class AttributeParser : public BaseParser
{
public:
    explicit AttributeParser(const std::string&);
    virtual ~AttributeParser() = default;
    virtual std::vector<DataParser> parse();

private:
    std::regex m_RegexValue;
};

#endif //DOMPARSER_ATTRIBUTEPARSER_H
