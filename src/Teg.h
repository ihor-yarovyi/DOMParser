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

	void setParent(Teg*);
	Teg* getParent() const;

	void setChildren(Teg*);
	std::vector<Teg*> getChildren() const;

	void setAttributeTeg(const std::string&);
	std::vector<std::string> getAttributeTeg() const;

	void setAttributeValueTeg(const std::string&);
	std::vector<std::string> getAttributeValueTeg() const;

	void setContent(const std::string&);
	std::string getContent() const;

private:
	std::string m_Name {};
	Teg* m_Parent;
	std::string m_Content {};
	std::vector<Teg*> m_Childrens {};
	std::vector<std::string> m_AttributeTeg {};
	std::vector<std::string> m_AttributeValueTeg {};

};


