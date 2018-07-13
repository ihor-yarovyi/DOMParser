#include "ContentParser.h"
#include <iostream>

ContentParser::ContentParser(const std::string& data)
: BaseParser(data),
  m_RegexValue("<([a-zA-Z_][\\w.-]*)([^>]*)>\\s*([\\w\\W]*?)\\s*<\\/\\1>")
{

}

std::vector<DataParser> ContentParser::parse()
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
            dataParser.setContentData(sm[1].str(), sm[2].str(), sm[3].str());
            result.emplace_back(dataParser);
            ++next;
        }
    }
    catch (const std::regex_error& e)
    {
        std::cout << e.what() << std::endl;
    }
    return result;
}
