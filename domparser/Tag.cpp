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

bool Tag::operator==(Tag* right)
{
	return m_Name == right->m_Name && m_Parent == right->m_Parent
		   && m_Content == right->m_Content && m_AttributeTeg == right->m_AttributeTeg
		   && m_AttributeValueTeg == right->m_AttributeValueTeg;
}

bool Tag::operator==(const Tag& right)
{
    return m_Name == right.m_Name && m_Parent == right.m_Parent
           && m_Content == right.m_Content && m_AttributeTeg == right.m_AttributeTeg
           && m_AttributeValueTeg == right.m_AttributeValueTeg;
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

std::string& Tag::getContent()
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

std::vector<std::string>& Tag::getAttributeTag()
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

std::vector<std::string>& Tag::getAttributeValueTag()
{
	return m_AttributeValueTeg;
}