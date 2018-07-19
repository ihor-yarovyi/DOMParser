#ifndef DOMPARSER_PAGEDATAIMPL_H
#define DOMPARSER_PAGEDATAIMPL_H

#include "IPageData.h"
#include "ProcessPage.h"

class PageDataImpl : public IPageData
{
public:
    PageDataImpl(const std::string&, const std::string&); // Path and rules
    ~PageDataImpl();

    virtual std::vector<Tag> getPageData(const std::string&) const = 0;
    // Navigation
    virtual Tag* first() = 0;
    virtual Tag* last() = 0;
    virtual Tag* next(Tag*) = 0;
    virtual Tag* prev(Tag*) = 0;
    virtual Tag* parent(Tag*) = 0;
    virtual std::vector<Tag*> children(Tag*) = 0;
    virtual std::vector<Tag*> sibling(Tag*) = 0;
    // Modification
    virtual bool insertAttribute(Tag*, const std::string&, const std::string&) = 0; // |
    virtual bool changeAttribute(Tag*, const std::string&, const std::string&) = 0; // |> tag, attribute name, attribute value
    virtual bool removeAttribute(Tag*, const std::string&, const std::string&) = 0; // |
    virtual bool removeTag(Tag*) = 0;
    virtual void pushBack(Tag*) = 0;
    virtual void pushFront(Tag*) = 0;
    virtual void pushBefore(Tag*, Tag*) = 0;
    virtual void pushAfter(Tag*, Tag*) = 0;
    virtual void changeContent(Tag*) = 0;
    virtual void removeContent(Tag*) = 0;
    // Get value of DOM element
    virtual std::string getTagName(Tag*) = 0;
    virtual std::string getTagContent(Tag*) = 0;
    virtual std::string getAttributeValue(Tag*, const std::string&) = 0;

private:
    ProcessPage m_ProcessPage;
    std::vector<Tag> m_Data;
};

#endif //DOMPARSER_PAGEDATAIMPL_H
