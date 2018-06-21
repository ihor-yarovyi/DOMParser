#include "AttributeValueParser.h"
#include <iostream>

AttibuteValueParser::AttibuteValueParser(const std::string& data)
: BaseParser(data),
  m_RegexValue("\"(.*?)\"|'(.*?)'|=\\s*(\\d+)")
{

}

std::vector<std::string> AttibuteValueParser::parse()
{
    std::vector<std::string> result {};

    try
    {
        std::sregex_iterator next(userData.begin(), userData.end(), m_RegexValue);
        std::sregex_iterator end;

        std::smatch sm;

        while (next != end)
        {
            sm = *next;

            if (sm.str().find_first_of("'") != std::string::npos)
            {
                result.emplace_back(sm[2].str());
                ++next;
                continue;
            }

            if (sm.str().find_first_of("=") != std::string::npos)
            {
                result.emplace_back(sm[3].str());
                ++next;
                continue;
            }

            result.push_back(sm[1].str());
            ++next;
        }
    }
    catch (const std::regex_error& e)
    {
        std::cout << e.what() << std::endl;
    }
    return result;
}