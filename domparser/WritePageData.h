#ifndef DOMPARSER_WRITEPAGEDATA_H
#define DOMPARSER_WRITEPAGEDATA_H

#include "IPageData.h"
#include "Tag.h"

#include <memory>
#include <string>
#include <fstream>

class WritePageData
{
public:
    WritePageData(std::shared_ptr<IPageData>, const std::string& = "pagedata.html");
    ~WritePageData() = default;
    void setPageData(std::shared_ptr<IPageData>);
    void writeToFile();

private:
    void writeToFileHelper(std::shared_ptr<IPageData>);

private:
    std::shared_ptr<IPageData> m_PageData;
    std::ofstream m_FileOutput;
};

#endif //DOMPARSER_WRITEPAGEDATA_H
