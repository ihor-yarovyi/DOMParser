#ifndef DOMPARSER_PAGEDATAIMPL_H
#define DOMPARSER_PAGEDATAIMPL_H

#include "IPageData.h"
#include "ProcessPage.h"

class PageDataImpl : public IPageData
{
public:
    PageDataImpl(const std::string&, const std::string&); // Path and rules
    ~PageDataImpl() = default;

    virtual size_t getNumberOfTags() const;
    virtual bool setCurrentTag(size_t);
    // Navigation
    virtual Tag* first();
    virtual Tag* last();
    virtual Tag* next();
    virtual Tag* prev();
    virtual Tag* parent() const;
    virtual Tag* current();
    virtual std::vector<Tag*> children() const;
    virtual std::vector<Tag*> siblings() const;
    // Modification
    virtual bool insertAttribute(const std::string&, const std::string&);
    virtual bool changeAttribute(const std::string&, const std::string&, const std::string&, const std::string&);
    virtual bool removeAttribute(const std::string&, const std::string&);
    virtual void removeTag(); // Remove current tag
    virtual void pushBack(const Tag&);
    virtual void pushFront(const Tag&);
    virtual bool pushBefore(const Tag&, const Tag&);
    virtual bool pushBefore(size_t, const Tag&);
    virtual bool pushAfter(const Tag&, const Tag&);
    virtual bool pushAfter(size_t, const Tag&);
    virtual bool changeContent(const std::string&);
    virtual bool removeContent();
    // Get value of DOM element
    virtual std::string getTagName() const;
    virtual std::string getTagContent() const;

private:
    bool compareTags(const Tag&, Tag*) const;

private:
    ProcessPage m_ProcessPage;
    std::vector<Tag> m_Data;
    size_t m_CurrentTag = 0;
};

#endif //DOMPARSER_PAGEDATAIMPL_H
