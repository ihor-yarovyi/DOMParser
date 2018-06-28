#include "DOMParser.h"

DOMParser::DOMParser(BaseParser* ptr)
: m_BaseParser(ptr)
{

}

std::vector<std::string> DOMParser::parse()
{
    return m_BaseParser->parse();
}