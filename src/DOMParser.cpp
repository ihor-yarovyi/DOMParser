#include "DOMParser.h"

DOMParser::DOMParser(BaseParser* ptr)
: m_BaseParser(ptr)
{

}

std::vector<DataParser> DOMParser::parse()
{
    return m_BaseParser->parse();
}