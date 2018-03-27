#pragma once
#include <string>
#include <vector>

class Teg
{
public:
	Teg(const std::string& = "");
	~Teg();

	void setTegName(const std::string&);
	std::string getTegName() const;

	void setParent(const std::string&);
	std::string getParent() const;

	void setChildren(const std::string&);
	std::vector<std::string> getChildren() const;

	void setTegProperties(const std::string&, const std::string&); // Attribute and his value
	std::vector<std::pair<std::string, std::string>> getTegProperties() const;

	void setContent(const std::string&);
	std::string getContent() const;

private:
	std::string m_Name {};
	std::string m_Parent {};
	std::string m_Content {};
	std::vector<std::string> m_Childrens {};
	std::vector<std::pair<std::string, std::string>> m_TegProperties {};

};


