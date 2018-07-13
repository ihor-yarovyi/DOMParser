#ifndef DOMPARSER_PAGEDATA_H
#define DOMPARSER_PAGEDATA_H

#include <vector>
#include "Teg.h"

class PageData
{
public:
    PageData() = default;
    ~PageData() = default;

    void add(const Teg&);
    std::vector<Teg> getData() const;
    bool empty() const;

    Teg& first();
    Teg& last();

private:
    std::vector<Teg> m_Page;
};


#endif //DOMPARSER_PAGEDATA_H
