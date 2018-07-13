#ifndef DOMPARSER_BASEPARSER_H
#define DOMPARSER_BASEPARSER_H

#include <vector>
#include <string>

#include "DataParser.h"

class BaseParser
{
public:
    BaseParser(const std::string& str)
    : userData(str)
    {}
    virtual ~BaseParser() = default;

    virtual std::vector<DataParser> parse() = 0;

    void setData(const std::string& str)
    {
        userData = str;
    }

protected:
    std::string userData;
};

#endif //DOMPARSER_BASEPARSER_H
