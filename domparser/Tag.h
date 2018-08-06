#ifndef DOMPARSER_TAG_H
#define DOMPARSER_TAG_H
#include <string>
#include <vector>

class Tag
{
public:
	Tag(const std::string& = "");
	~Tag();

	bool operator==(Tag*);
	bool operator==(const Tag&);

	void setTagName(const std::string&);
	std::string getTagName() const;

	void setParent(Tag*);
	Tag* getParent() const;

	void setChildren(Tag*);
	std::vector<Tag*> getChildren() const;

	void setAttributeTag(const std::string &);
	std::vector<std::string> getAttributeTag() const;
	std::vector<std::string>& getAttributeTag();

	void setAttributeValueTag(const std::string &);
	std::vector<std::string> getAttributeValueTag() const;
	std::vector<std::string>& getAttributeValueTag();

	void setContent(const std::string&);
	std::string getContent() const;
	std::string& getContent();

private:
	std::string m_Name {};
	Tag* m_Parent;
	std::string m_Content {};
	std::vector<Tag*> m_Childrens {};
	std::vector<std::string> m_AttributeTag {};
	std::vector<std::string> m_AttributeValueTag {};
};

#endif //DOMPARSER_TAG_H


