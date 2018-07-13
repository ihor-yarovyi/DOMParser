#ifndef DOMPARSER_PROCESSPAGE_H
#define DOMPARSER_PROCESSPAGE_H

#include <string>
#include <memory>

#include "BaseParser.h"
#include "PageData.h"

class ProcessPage
{
public:
    ProcessPage(const std::string&);
    ~ProcessPage() = default;

    void setWebPage(const std::string&);
    void process();
    PageData getData() const;

private:
    void processInputPageHelper(const std::string&);
    PageData processHelper(const std::string&, PageData&);

private:
    std::shared_ptr<BaseParser> m_BasePtr;
    std::string m_InputPage {};
    PageData m_PageData;
};


#endif //DOMPARSER_PROCESSPAGE_H
