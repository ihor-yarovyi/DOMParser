#ifndef DOMPARSER_PAGEDATA_H
#define DOMPARSER_PAGEDATA_H

#include <vector>
#include "Tag.h"

class PageData
{
public:
    PageData() = default;
    ~PageData() = default;

    void add(const Tag&);
    std::vector<Tag> getData() const;
    bool empty() const;

    Tag& first();
    Tag& last();

private:
    std::vector<Tag> m_Page;
};


#endif //DOMPARSER_PAGEDATA_H
