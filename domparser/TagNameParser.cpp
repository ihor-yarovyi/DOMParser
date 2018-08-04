#include "TagNameParser.h"

TagNameParser::TagNameParser(const std::string& data)
: BaseParser(data),
  m_RegexValue("<([\\w]+)")
{

}

std::vector<DataParser> TagNameParser::parse()
{
    std::vector<DataParser> result {};

    try
    {
        DataParser dataParser;
        std::cmatch value;
        std::regex_search(userData.data(), value, m_RegexValue);
        dataParser.setTagName(value[1].str());
        result.emplace_back(dataParser);
    }
    catch (const std::regex_error&)
    {
        throw;
    }
    return result;
}