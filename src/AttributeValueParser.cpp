#include "AttributeValueParser.h"
#include <iostream>

AttibuteValueParser::AttibuteValueParser(const std::string& data)
: BaseParser(data),
  m_RegexValue("\".*?\"|'.*?'")
{

}

std::vector<std::string> AttibuteValueParser::parse()
{
    std::vector<std::string> result {};

    std::sregex_iterator next(userData.begin(), userData.end(), m_RegexValue);
    std::sregex_iterator end;

    try
    {
        while (next != end)
        {
            result.push_back(std::smatch(*next).str());
            ++next;
        }
    }
    catch (const std::regex_error& e)
    {
        std::cout << e.what() << std::endl;
    }
    return result;
}