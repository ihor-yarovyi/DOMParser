#ifndef DOMPARSER_BASEPARSER_H
#define DOMPARSER_BASEPARSER_H

#include <vector>
#include <string>

class BaseParser
{
public:
    BaseParser(const std::string& str)
    : userData(str)
    {}
    virtual ~BaseParser() = default;

    virtual std::vector<std::string> parse() = 0;

protected:
    std::string userData;
};

#endif //DOMPARSER_BASEPARSER_H
