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
    // Navigation
    virtual Tag* first() const;
    virtual Tag* last() const;
    virtual Tag* next();
    virtual Tag* prev();
    virtual Tag* parent() const;
    virtual std::vector<Tag*> children() const;
    virtual std::vector<Tag*> siblings() const;
    // Modification
    virtual bool insertAttribute(const std::string&, const std::string&) = 0;
    virtual bool changeAttribute(const std::string&, const std::string&, const std::string&);


private:
    ProcessPage m_ProcessPage;
    std::vector<Tag> m_Data;
    size_t m_CurrentTag = 0;
};

#endif //DOMPARSER_PAGEDATAIMPL_H
