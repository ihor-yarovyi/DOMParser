#ifndef DOMPARSER_PROCESSPAGE_H
#define DOMPARSER_PROCESSPAGE_H

#include <string>
#include <memory>
#include <vector>

#include "BaseParser.h"
#include "Teg.h"

class ProcessPage
{
public:
    ProcessPage(const std::string&);
    ~ProcessPage() = default;

    void setWebPage(const std::string&);
    void process();
    std::vector<Teg> getPageData() const;

private:
    void processInputPageHelper(const std::string&);
    std::vector<Teg> processHelper(const std::string&, std::vector<Teg>&, Teg*);

private:
    std::string m_InputPage {};
    std::vector<Teg> m_PageData;
};


#endif //DOMPARSER_PROCESSPAGE_H
