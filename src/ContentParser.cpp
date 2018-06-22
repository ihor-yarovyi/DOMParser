#include "ContentParser.h"
#include <iostream>

ContentParser::ContentParser(const std::string& data)
: BaseParser(data),
  m_RegexValue("<(\\w[\\w.-]*)[^>]*>\\s*([\\w\\W]*?)\\s*<\\/\\1>")
{

}

std::vector<std::string> ContentParser::parse()
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
            result.push_back(sm[2].str());
            ++next;
        }
    }
    catch (const std::regex_error& e)
    {
        std::cout << e.what() << std::endl;
    }
    return result;
}
