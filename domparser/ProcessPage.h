#ifndef DOMPARSER_PROCESSPAGE_H
#define DOMPARSER_PROCESSPAGE_H

#include <string>
#include <memory>
#include <vector>

#include "BaseParser.h"
#include "Tag.h"

class ProcessPage
{
public:
    ProcessPage(const std::string&);
    ~ProcessPage() = default;

    void setWebPage(const std::string&);
    void process();
    std::vector<Tag> getPageData() const;

private:
    void processInputPageHelper(const std::string&);
    std::vector<Tag> processHelper(const std::string&, std::vector<Tag>&, Tag*);

private:
    std::string m_InputPage {};
    std::vector<Tag> m_PageData;
};


#endif //DOMPARSER_PROCESSPAGE_H
