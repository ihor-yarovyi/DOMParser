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
    virtual bool insertAttribute(const std::string&, const std::string&) = 0;
    virtual bool changeAttribute(const std::string&, const std::string&, const std::string&);

private:
    bool compareTags(const Tag&, Tag*) const;

private:
    ProcessPage m_ProcessPage;
    std::vector<Tag> m_Data;
    size_t m_CurrentTag = 0;
};

#endif //DOMPARSER_PAGEDATAIMPL_H
