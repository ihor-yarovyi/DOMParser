#include "DataParser.h"

void DataParser::setContentData(const std::string& tegName, const std::string& noParsingAttribute, const std::string& content)
{
    m_TagName = tegName;
    m_NotParsingAttributes = noParsingAttribute;
    m_Content = content;
}


void DataParser::setTagName(const std::string &str)
{
    m_TagName = str;
}

void DataParser::setAttribute(const std::string& str)
{
    m_Attribute = str;
}

void DataParser::setAttributeValue(const std::string& str)
{
    m_AttributeValue = str;
}

std::string DataParser::getTagName() const
{
    return m_TagName;
}

std::string DataParser::getAttribute() const
{
    return m_Attribute;
}

std::string DataParser::getAttributeValue() const
{
    return m_AttributeValue;
}

std::string DataParser::getNotParsingAttributes() const
{
    return m_NotParsingAttributes;
}

std::string DataParser::getContent() const
{
    return m_Content;
}

