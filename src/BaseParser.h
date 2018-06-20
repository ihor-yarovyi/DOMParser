#ifndef DOMPARSER_BASEPARSER_H
#define DOMPARSER_BASEPARSER_H

#include <vector>
#include <string>

class BaseParser
{
public:
    BaseParser() = default;
    ~BaseParser() = default;

    virtual std::vector<std::string> parse() = 0;
};

#endif //DOMPARSER_BASEPARSER_H
