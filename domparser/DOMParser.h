#ifndef DOMPARSER_DOMPARSER_H
#define DOMPARSER_DOMPARSER_H

#include "BaseParser.h"

#include <vector>
#include <string>
#include <memory>

class DOMParser 
{
public:
    DOMParser(BaseParser*);
    ~DOMParser() = default;

    std::vector<DataParser> parse();

private:
    std::shared_ptr<BaseParser> m_BaseParser;
};

#endif // DOMPARSER_DOMPARSER_H