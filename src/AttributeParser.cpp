#include "AttributeParser.h"
#include <iostream>

AttributeParser::AttributeParser(const std::string& data)
: BaseParser(),
  userData(data),
  m_RegexValue("\".*?\"|'.*?'")
{

}

std::vector<std::string> AttributeParser::parse()
{
    std::vector<std::string> result {};
    try
    {
        std::sregex_iterator next(str.begin(), str.end(), m_regValue);
        std::sregex_iterator end;
        while (next != end)
        {
            result.push_back(std::smatch(*next).str());
            ++next;
        }
    }
    catch (std::regex_error& e)
    {
        std::cout << e.what() << std::endl;
    }

    return result;
}



