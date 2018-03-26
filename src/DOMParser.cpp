#include "DOMParser.h"

DOMParser::DOMParser(const std::string& fileData)
	: m_FileData(fileData)
{

}

DOMParser::~DOMParser()
{

}

void DOMParser::parseFileData()
{
	// TODO: remake parse file data
	size_t firstPosition = m_FileData.find_first_of("<");
	size_t lastPosition = m_FileData.find_first_of(">");

	while (firstPosition != std::string::npos && lastPosition != std::string::npos)
	{
		m_FileData.substr(firstPosition, lastPosition - firstPosition + 1);

		size_t newStartPosition = lastPosition;

		firstPosition = m_FileData.find_first_of("<", newStartPosition + 1);
		lastPosition = m_FileData.find_first_of(">", newStartPosition + 1);
	}
}

void DOMParser::parseTeg(const std::string& tegString)
{
	// TODO: make parse teg
}

std::string DOMParser::getTegName(const std::string& str)
{
	size_t position = str.find_first_of(' ');
	
	if (position == std::string::npos)
	{
		return str;
	}
	else
	{
		return std::string(str.begin(), str.begin() + position);
	}
	return {};
}