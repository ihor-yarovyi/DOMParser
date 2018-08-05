#ifndef DOMPARSER_WRITEPAGEDATA_H
#define DOMPARSER_WRITEPAGEDATA_H

#include "IPageData.h"
#include <memory>

class WritePageData
{
public:
    explicit WritePageData(std::unique_ptr<IPageData>);
    ~WritePageData() = default;
    void setPageData(std::unique_ptr<IPageData>);
    void writeToFile();

private:
    std::unique_ptr<IPageData> m_PageData;
};


#endif //DOMPARSER_WRITEPAGEDATA_H
