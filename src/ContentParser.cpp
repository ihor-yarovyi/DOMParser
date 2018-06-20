#include "ContentParser.h"
#include <iostream>

ContentParser::ContentParser(const std::string& data)
: BaseParser(data),
  m_RegexValue("<.+>\\s*(.+)\\s*<\\/.+>")
{

}

std::vector<std::string> ContentParser::parse()
{
    std::vector<std::string> result {};

    try
    {
        std::sregex_iterator next(userData.begin(), userData.end(), m_RegexValue);
        std::sregex_iterator end;

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
