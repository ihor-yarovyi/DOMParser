#include "TegNameParser.h"
#include <iostream>

TegNameParser::TegNameParser(const std::string& data)
: BaseParser(data),
  m_RegexValue("<([\\w]+)")
{

}

std::vector<DataParser> TegNameParser::parse()
{
    std::vector<DataParser> result {};

    try
    {
        DataParser dataParser;
        std::cmatch value;
        std::regex_search(userData.data(), value, m_RegexValue);
        dataParser.setTegName(value[1].str());
        result.emplace_back(dataParser);
    }
    catch (const std::regex_error& e)
    {
        std::cout << e.what() << std::endl;
    }
    return result;
}