#include "AttributeValueParser.h"
#include <iostream>

AttibuteValueParser::AttibuteValueParser(const std::string& data)
: BaseParser(data),
  m_RegexValue("\"(.*?)\"|'(.*?)'|=\\s*(\\d+)")
{

}

std::vector<DataParser> AttibuteValueParser::parse()
{
    std::vector<DataParser> result {};

    try
    {
        std::sregex_iterator next(userData.begin(), userData.end(), m_RegexValue);
        std::sregex_iterator end;

        std::smatch sm;

        while (next != end)
        {
            sm = *next;
            DataParser dataParser;
            if (sm.str().find_first_of("'") != std::string::npos)
            {
                dataParser.setAttributeValue(sm[2].str());
                result.emplace_back(dataParser);
                ++next;
                continue;
            }

            if (sm.str().find_first_of("=") != std::string::npos)
            {
                dataParser.setAttributeValue(sm[3].str());
                result.emplace_back(dataParser);
                ++next;
                continue;
            }

            dataParser.setAttributeValue(sm[1].str());
            result.push_back(dataParser);
            ++next;
        }
    }
    catch (const std::regex_error& e)
    {
        std::cout << e.what() << std::endl;
    }
    return result;
}