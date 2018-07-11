#include "Teg.h"

Teg::Teg(const std::string& tegName)
	: m_Name(tegName),
      m_Parent(nullptr)
{

}

Teg::~Teg()
{
    m_Parent = nullptr;
}

void Teg::setTegName(const std::string& tegName)
{
	m_Name = tegName;
}

std::string Teg::getTegName() const
{
	return m_Name;
}

void Teg::setContent(const std::string& constentValue)
{
	m_Content = constentValue;
}

std::string Teg::getContent() const
{
	return m_Content;
}

void Teg::setParent(Teg* ptr)
{
	m_Parent = ptr;
}

Teg* Teg::getParent() const
{
	return m_Parent;
}

void Teg::setChildren(Teg* ptr)
{
	m_Childrens.emplace_back(ptr);
}

std::vector<Teg*> Teg::getChildren() const
{
	return m_Childrens;
}

void Teg::setAttributeTeg(const std::string& data)
{
    m_AttributeTeg.emplace_back(data);
}

std::vector<std::string> Teg::getAttributeTeg() const
{
    return m_AttributeTeg;
}

void Teg::setAttributeValueTeg(const std::string& data)
{
    m_AttributeValueTeg.emplace_back(data);
}

std::vector<std::string> Teg::getAttributeValueTeg() const
{
    return m_AttributeValueTeg;
}