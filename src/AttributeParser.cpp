#include "AttributeParser.h"
#include <iostream>

AttributeParser::AttributeParser(const std::string& data)
: BaseParser(data),
  m_RegexValue("([\\w]+[\\s]*)=")
{

}

std::vector<DataParser> AttributeParser::parse()
{
    std::vector<DataParser> result {};
    try
    {
        std::sregex_iterator next(userData.begin(), userData.end(), m_RegexValue);
        std::sregex_iterator end;
        std::smatch sm;
        while (next != end)
        {
            DataParser dataParser;
            sm = *next;
            dataParser.setAttribute(sm[1].str());
            result.emplace_back(dataParser);
            ++next;
        }
    }
    catch (std::regex_error& e)
    {
        std::cout << e.what() << std::endl;
    }

    return result;
}



