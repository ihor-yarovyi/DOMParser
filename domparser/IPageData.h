#ifndef DOMPARSER_IPAGEDATA_H
#define DOMPARSER_IPAGEDATA_H

#include <vector>
#include <string>

#include "Tag.h"

class IPageData
{
public:
    IPageData() = default;
    virtual ~IPageData() = default;

    virtual size_t getNumberOfTags() const = 0;
    virtual bool setCurrentTag(size_t) = 0;
    // Navigation
    virtual Tag* first() = 0;
    virtual Tag* last() = 0;
    virtual Tag* next() = 0;
    virtual Tag* prev() = 0;
    virtual Tag* parent() const = 0;
    virtual Tag* current() = 0;
    virtual std::vector<Tag*> children() const = 0;
    virtual std::vector<Tag*> siblings() const = 0;
    // Modification
    virtual bool insertAttribute(const std::string&, const std::string&) = 0;
    virtual bool changeAttribute(const std::string&, const std::string&, const std::string&, const std::string&) = 0;
    virtual bool removeAttribute(const std::string&, const std::string&) = 0;
    virtual void removeTag() = 0; // Remove current tag
    virtual void pushBack(const Tag&) = 0;
    virtual void pushFront(const Tag&) = 0;
    virtual bool pushBefore(const Tag&, const Tag&) = 0;
    virtual bool pushBefore(size_t, const Tag&) = 0;
    virtual bool pushAfter(const Tag&, const Tag&) = 0;
    virtual bool pushAfter(size_t, const Tag&) = 0;
    virtual bool changeContent(const std::string&) = 0;
    virtual bool removeContent() = 0;
//    // Get value of DOM element
    virtual std::string getTagName() const = 0;
    virtual std::string getTagContent() const = 0;
    virtual std::string getAttributeValue(const std::string&) const = 0;
};

#endif //DOMPARSER_IPAGEDATA_H
