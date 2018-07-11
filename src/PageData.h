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

private:
    std::vector<Teg> m_Page;
};


#endif //DOMPARSER_PAGEDATA_H
