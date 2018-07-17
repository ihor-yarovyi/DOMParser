#pragma once
#include <string>
#include <vector>

class Tag
{
public:
	Tag(const std::string& = "");
	~Tag();

	bool operator==(Tag*);

	void setTagName(const std::string&);
	std::string getTagName() const;

	void setParent(Tag*);
	Tag* getParent() const;

	void setChildren(Tag*);
	std::vector<Tag*> getChildren() const;

	void setAttributeTag(const std::string &);
	std::vector<std::string> getAttributeTag() const;

	void setAttributeValueTag(const std::string &);
	std::vector<std::string> getAttributeValueTag() const;

	void setContent(const std::string&);
	std::string getContent() const;

private:
	std::string m_Name {};
	Tag* m_Parent;
	std::string m_Content {};
	std::vector<Tag*> m_Childrens {};
	std::vector<std::string> m_AttributeTeg {};
	std::vector<std::string> m_AttributeValueTeg {};

};


