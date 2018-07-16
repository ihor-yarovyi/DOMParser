#include "Tag.h"

Tag::Tag(const std::string& tegName)
	: m_Name(tegName),
      m_Parent(nullptr)
{

}

Tag::~Tag()
{
    m_Parent = nullptr;
}

void Tag::setTagName(const std::string& tagName)
{
	m_Name = tagName;
}

std::string Tag::getTagName() const
{
	return m_Name;
}

void Tag::setContent(const std::string& constentValue)
{
	m_Content = constentValue;
}

std::string Tag::getContent() const
{
	return m_Content;
}

void Tag::setParent(Tag* ptr)
{
	m_Parent = ptr;
}

Tag* Tag::getParent() const
{
	return m_Parent;
}

void Tag::setChildren(Tag* ptr)
{
	m_Childrens.emplace_back(ptr);
}

std::vector<Tag*> Tag::getChildren() const
{
	return m_Childrens;
}

void Tag::setAttributeTag(const std::string &data)
{
    m_AttributeTeg.emplace_back(data);
}

std::vector<std::string> Tag::getAttributeTag() const
{
    return m_AttributeTeg;
}

void Tag::setAttributeValueTag(const std::string &data)
{
    m_AttributeValueTeg.emplace_back(data);
}

std::vector<std::string> Tag::getAttributeValueTag() const
{
    return m_AttributeValueTeg;
}