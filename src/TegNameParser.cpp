#include "TegNameParser.h"
#include <iostream>

TegNameParser::TegNameParser(const std::string& data)
: BaseParser(data),
  m_RegexValue("<(\\w+)")
{

}

std::vector<std::string> TegNameParser::parse()
{
    std::vector<std::string> result {};

    try
    {
        std::sregex_iterator next(userData.begin(), userData.end(), m_RegexValue);
        std::sregex_iterator end;

        std::smatch sm;
        while (next != end)
        {
            result.push_back(std::smatch(*next)[1].str());
            ++next;
        }
    }
    catch (const std::regex_error& e)
    {
        std::cout << e.what() << std::endl;
    }
    return result;
}