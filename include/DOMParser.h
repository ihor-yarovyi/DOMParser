#pragma once

#include <string>

class DOMParser 
{
public:
	DOMParser(const std::string&);
	~DOMParser();

	void parseFileData();
	void parseTeg(const std::string&);
	std::string getTegName(const std::string&);

private:
	std::string m_FileData;

};