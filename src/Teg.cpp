#include "Teg.h"

Teg::Teg(const std::string& tegName)
	: m_Name(tegName)
{

}

Teg::~Teg()
{

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

void Teg::setParent(const std::string& parentTeg)
{
	m_Parent = parentTeg;
}

std::string Teg::getParent() const
{
	return m_Parent;
}

void Teg::setChildren(const std::string& children)
{
	m_Childrens.push_back(children);
}

std::vector<std::string> Teg::getChildren() const
{
	return m_Childrens;
}

void Teg::setTegProperties(const std::string& attributeName, const std::string& attributeValue)
{
	m_TegProperties.push_back({ attributeName, attributeValue });
}

std::vector<std::pair<std::string, std::string>> Teg::getTegProperties() const
{
	return m_TegProperties;
}