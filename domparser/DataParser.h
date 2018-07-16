#ifndef DOMPARSER_DATAPARSER_H
#define DOMPARSER_DATAPARSER_H

#include <string>

class DataParser
{
public:
    DataParser() = default;
    ~DataParser() = default;

    void setContentData(const std::string&, const std::string&, const std::string&);
    void setAttribute(const std::string&);
    void setAttributeValue(const std::string&);
    void setTagName(const std::string &);

    std::string getTagName() const;
    std::string getNotParsingAttributes() const;
    std::string getContent() const;
    std::string getAttribute() const;
    std::string getAttributeValue() const;

private:
    std::string m_TagName {};
    std::string m_NotParsingAttributes {};
    std::string m_Content {};
    std::string m_Attribute {};
    std::string m_AttributeValue {};
};


#endif //DOMPARSER_DATAPARSER_H
